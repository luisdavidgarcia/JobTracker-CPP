CREATE TABLE jobs (
    id SERIAL PRIMARY KEY, 
    company_name TEXT NOT NULL,
    position_title TEXT NOT NULL,
    applied_date DATE,
    max_salary INTEGER,
    company_challenge TEXT,
    required_skills TEXT,
    job_requirements TEXT
);
