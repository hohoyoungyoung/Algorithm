-- 코드를 입력하세요
#SELECT DATETIME as '시간'
#from ANIMAL_INS a
#WHERE a.DATETIME = (SELECT MIN(DATETIME)
#                   FROM ANIMAL_INS b)
                   
                   

SELECT MIN(DATETIME)
FROM ANIMAL_INS