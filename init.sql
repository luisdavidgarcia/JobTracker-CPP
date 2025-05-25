CREATE TABLE jobs (
    id SERIAL PRIMARY KEY, 
    company_name TEXT NOT NULL,
    position_title TEXT NOT NULL,
    applied_date DATE,
    salary_range TEXT,
    company_challenge TEXT,
    required_skills TEXT
);
