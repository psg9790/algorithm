-- 코드를 입력하세요
SELECT PT_NAME, PT_NO, GEND_CD, AGE, ifnull(TLNO, 'NONE') from PATIENT 
where AGE <= 12 AND GEND_CD = 'W' 
ORDER by AGE desc, PT_NAME asc;