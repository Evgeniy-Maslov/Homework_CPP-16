insert into Genre(name) values 
('Jazz'),
('Classic Rock'),
('Pop');

insert into Singer(name) values
('Louis Armstrong'),
('Ray Charle'),
('The Beatles'),
('Paul McCartney'),
('Dua Lipa'),
('Sting');

insert into Genre_Singer(Genre_id, Singer_id) values
(1, 1),
(1, 2),
(2, 3),
(2, 4),
(3, 5),
(3, 6),
(3, 4);

insert into Albom(name, year_release) values 
('Satchmo Serenades', 1952),
('What A Wonderful World', 1967),
('The Genius Hits the Road', 1960),
('Ray Charles Live', 1973),
('Beatles for Sale', 1964),
('Yellow Submarine', 1969),
('Ram', 1971),
('Paul Is Live', 1993),
('Future Nostalgia', 2020),
('Daytrotter Session', 2016),
('…Nothing Like the Sun', 1987),
('Brand New Day', 1999);

insert into Singer_Albom(Singer_id, Albom_id) values
(1, 1),
(1, 2),
(2, 3),
(2, 4),
(3, 5),
(3, 6),
(4, 7),
(4, 8),
(5, 9),
(5, 10),
(6, 11),
(6, 12);

insert into Track(name, duration, Albom_id) values 
('A Kiss to Build a Dream On', 3, 1),
('Cest si bon', 3.31, 1),
('What a Wonderful World', 2.18, 2),
('Cabaret', 3.10, 2),
('Alabamy bound', 1.54, 3),
('Moon over miami', 3.20, 3),
('Hot rod', 3.44, 4),
('Blues Waltz', 6.28, 4),
('No reply', 2.16, 5),
('Kansas city', 2.33, 5),
('Yellow Submarine', 2.40, 6),
('All together now', 1.54, 6),
('Ram on', 2.30, 7),
('Legs', 2.48, 7),
('Drive my car', 2.33, 8),
('All my loving', 2.16, 8),
('Future Nostalgia', 3.05, 9),
('Levitating', 3.24, 9),
('Be the one', 3.14, 10),
('The lazarus heart', 4.36, 11),
('Fragile', 3.55, 11),
('Fill hep up', 5.38, 12);

insert into Collection(name, year_release) values 
('Collection_1', 2016),
('Collection_2', 2018),
('Collection_3', 2020),
('Collection_4', 2022);

insert into Collection_Track(Collection_id, Track_id) values 
(1, 2),
(1, 7),
(1, 21),
(2, 4),
(2, 1),
(2, 18),
(3, 5),
(3, 22),
(3, 15),
(4, 8),
(4, 13),
(4, 19);