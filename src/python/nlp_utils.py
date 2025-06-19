import spacy
from datetime import datetime


class JobProcessor:
    def __init__(self, model: str = "en_core_web_sm"):
        self.nlp = spacy.load("en_core_web_sm")

    def _add_date(self, result: dict):
        result["applied_date"] = datetime.now().strftime("%Y-%m-%d") 

    def _add_company_name(self, doc_ents, result: dict):
        for ent in doc_ents:
            if ent.label_ == "ORG":
                result["company_name"] = ent.text
                break

    def _add_position(self, doc, result: dict):
        position_keywords = ["developer", "engineer", "test automation"]
        for token in doc:
            if token.lower_ in position_keywords:
                result["position_title"] = token.text

    def _add_max_salary(self, doc_ents, result: dict):
        money_entities = [ent for ent in doc_ents if ent.label_ == "MONEY"]
        if money_entities:
            max_salary = ""
            for ent in money_entities:
                if "-" in ent.text:
                    max_salary = ent.text.split("-")[1]
                    break
                elif "to" in ent.text:
                    max_salary = ent.text.split("to")[1]
                    break

            if max_salary != "":
                result["max_salary"] = int(max_salary)

    def _add_required_skills(self, doc_noun_chunks, result: dict):
        skill_keywords = {
            "python", "c++", "c", "java", "aws", "docker", "azure", 
            "kubernetes", "sql", "mongodb", "jtag", "oscilloscope", 
            "unit tests", "ci/cd","go", "rust", "javascript", "fpga", "xilinx", 
            "vivado", "ltspice", "git", "linux", "embedded linux", "cmake", 
            "rtos", "arm cortex-m", "device drivers", "bootloaders", 
            "bare-metal", "i2c", "uart", "can", "adc", "signal processing", 
            "matlab", "clang", "gdb", "wireshark", "bluetooth", "ethernet", 
            "google test", "boost", "zephyr"
        }

        required_skills = set()
        for np in doc_noun_chunks:
            np_text = np.text.lower()

            if np_text in skill_keywords:
                required_skills.add(np_text)

        if required_skills:
            result["required_skills"] = ", ".join(required_skills)
     
    def _add_responsibilities(self, doc_sents, result: dict):
        responsibilities_keywords = [
            "requirements", "qualifications", "desired skills", "must have", 
            "experience with", "responsibilities"
        ]

        responsibilities = []
        capturing_responsibilities = False
        for sent in doc_sents:
            if any(keyword in sent.text.lower() for keyword in responsibilities_keywords):
                capturing_responsibilities = True

            if capturing_responsibilities:
                responsibilities.append(sent.text.strip())

            if capturing_responsibilities and not sent.text.strip():
                break
        
        if responsibilities:
            result["responsibilities"] = " ".join(responsibilities)
     

    def extract_job_info(self, text: str):
        doc = self.nlp(text)
        
        result = {
            "company_name": "",
            "position_title": "",
            "applied_date": None,
            "max_salary": 0,
            "company_challenge": "",
            "required_skills": "",
            "responsibilities": "" 
        }

        self._add_date(result)
        self._add_company_name(doc.ents, result)
        self._add_position(doc, result)
        self._add_max_salary(doc.ents, result)
        self._add_required_skills(doc.noun_chunks, result)
        self._add_responsibilities(doc.sents, result)
                           
        return result

