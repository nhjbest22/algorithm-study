SELECT
    ID,
    EMAIL,
    FIRST_NAME,
    LAST_NAME
FROM 
    DEVELOPERS
WHERE
    FLOOR(SKILL_CODE / (
        SELECT 
            CODE
        FROM
            SKILLCODES
        WHERE 
            NAME = 'C#'
    )) % 2 = 1
    OR
    FLOOR(SKILL_CODE / (
        SELECT 
            CODE
        FROM
            SKILLCODES
        WHERE 
            NAME = 'Python'
    )) % 2 = 1
ORDER BY 
    ID ASC;

