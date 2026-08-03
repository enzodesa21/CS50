--Em 6.sql, escreva uma consulta SQL para determinar a avaliação média de todos os filmes lançados em 2012.

SELECT AVG(rating) FROM ratings
JOIN movies ON movies.id = ratings.movie_id

WHERE movies.year == 2012;
