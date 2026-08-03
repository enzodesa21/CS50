--Em 13.sql, escreva uma consulta SQL para listar os nomes de todas as pessoas que estrelaram um filme no qual Kevin Bacon também estrelou.

SELECT name FROM people

JOIN stars ON stars.person_id = people.id
JOIN movies ON movies.id = stars.movie_id

WHERE movies.id IN
(
    SELECT stars.movie_id FROM stars

    JOIN people ON people.id = stars.person_id

    WHERE people.name LIKE "Kevin Bacon"
);
