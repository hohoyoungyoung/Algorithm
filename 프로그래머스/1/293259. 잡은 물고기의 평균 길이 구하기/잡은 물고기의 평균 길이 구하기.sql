SELECT ROUND(
           AVG(
               COALESCE(length, 10)
           ), 2
       ) AS AVERAGE_LENGTH
FROM fish_info;
