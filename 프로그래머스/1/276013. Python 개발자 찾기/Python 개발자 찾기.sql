-- 코드를 작성해주세요
SELECT ID, email, FIRST_NAME, LAST_NAME
from DEVELOPER_INFOS
WHERE (SKILL_1 = 'Python') or (SKILL_2 = 'Python') or (SKILL_3 = 'Python')
order by id asc;