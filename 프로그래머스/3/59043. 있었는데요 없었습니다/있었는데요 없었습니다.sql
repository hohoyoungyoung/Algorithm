-- 코드를 입력하세요
SELECT O.ANIMAL_ID, O.NAME
FROM ANIMAL_INS I, ANIMAL_OUTS O
WHERE I.ANIMAL_ID = O.ANIMAL_ID 
AND I.DATETIME > O.DATETIME
ORDER BY I.DATETIME ASC



# ANIMAL OUT에 입양일, ANIMAL IN에 보호 시작일 있음 