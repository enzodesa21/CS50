--Em 11.sql, escreva uma consulta SQL para listar os títulos dos cinco filmes com melhor classificação (em ordem) que Chadwick Boseman estrelou,
--começando com os de maior classificação.

SELECT title FROM movies

JOIN ratings ON ratings.movie_id = movies.id
JOIN stars ON stars.movie_id = ratings.movie_id
JOIN people ON people.id = stars.person_id

WHERE people.name LIKE "Chadwick Boseman"
ORDER BY ratings.rating DESC
LIMIT 5;
