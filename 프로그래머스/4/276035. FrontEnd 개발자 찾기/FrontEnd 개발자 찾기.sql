# SELECT
#     D.ID,
#     D.EMAIL,
#     D.FIRST_NAME,
#     D.LAST_NAME
# FROM
#     DEVELOPERS D
# WHERE
#     D.SKILL_CODE & (
#         SELECT
#             SUM(CODE)
#         FROM
#             SKILLCODES
#         WHERE
#             CATEGORY = 'Front End'
#     )
# ORDER BY
#     D.ID ASC;

SELECT
    D.ID,
    D.EMAIL,
    D.FIRST_NAME,
    D.LAST_NAME
FROM
    DEVELOPERS D
WHERE
    EXISTS (
        SELECT
            1
        FROM
            SKILLCODES S
        WHERE
            S.CATEGORY = 'Front End'
        AND
            S.CODE & D.SKILL_CODE
    )
ORDER BY
    D.ID ASC;