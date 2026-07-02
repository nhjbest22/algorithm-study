-- SELECT
--     ANIMAL_ID,
--     NAME
-- FROM
--     ANIMAL_OUTS
-- WHERE
--     ANIMAL_ID NOT IN
--         (
--             SELECT 
--                 ANIMAL_ID
--             FROM
--                 ANIMAL_INS
--         )
-- ORDER BY
--     ANIMAL_ID ASC;

WITH I AS (
    SELECT 
        ANIMAL_ID
    FROM
        ANIMAL_INS
)

SELECT
    ANIMAL_ID,
    NAME
FROM 
    ANIMAL_OUTS O
WHERE
    O.ANIMAL_ID
    NOT IN
    (SELECT ANIMAL_ID FROM I)
ORDER BY
    ANIMAL_ID ASC;