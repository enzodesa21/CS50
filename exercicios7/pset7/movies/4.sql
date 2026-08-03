--Em 4.sql, escreva uma consulta SQL para determinar o número de filmes com uma classificação IMDb de 10,0.

SELECT COUNT(movie_id) FROM ratings WHERE rating == 10.0;
