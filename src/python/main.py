from fastapi import FastAPI, Request
from pydantic import BaseModel
from datetime import date
from src.nlp_utils import JobProcessor

app = FastAPI()
job_processor = JobProcessor()

@app.post("/job_description")
async def create_job_description(request: Request):
    body = await request.body()

    job_description_text = body.decode('utf-8')
    
    result = job_processor.extract_job_info(job_description_text)

    print(result)

    return result

