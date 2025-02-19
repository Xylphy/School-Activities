CREATE TABLE ArtGallery (
    artwork_id INT AUTO_INCREMENT PRIMARY KEY,
    title VARCHAR(100),
    artist VARCHAR(100),
    year_created INT,
    medium VARCHAR(50),
    width_cm DECIMAL(5, 2),
    height_cm DECIMAL(5, 2),
    price DECIMAL(10, 2),
    exhibition_start_date DATE,
    exhibition_end_date DATE
);

INSERT INTO ArtGallery (title, artist, year_created, medium, width_cm, height_cm, price, exhibition_start_date, exhibition_end_date) 
VALUES 
('Sunset Bliss', 'Emma Brown', 2021, 'Oil on Canvas', 60.5, 45.0, 1200.00, '2024-01-10', '2024-02-15'),
('Urban Landscape', 'John Smith', 2019, 'Acrylic', 80.0, 60.0, 1500.00, '2024-03-01', '2024-03-30'),
('The Lone Tree', 'Sarah Johnson', 2020, 'Watercolor', 50.0, 70.0, 900.00, '2024-04-05', '2024-05-10'),
('Misty Mountains', 'Mike Davis', 2022, 'Oil on Canvas', 65.0, 50.0, 1100.00, '2024-01-15', '2024-02-20'),
('Abstract Thoughts', 'Laura Green', 2018, 'Acrylic', 90.0, 70.0, 2000.00, '2024-03-10', '2024-04-05'),
('Golden Fields', 'Robert Lee', 2017, 'Watercolor', 55.0, 65.0, 950.00, '2024-04-20', '2024-06-01'),
('City at Night', 'Anna Bell', 2023, 'Oil on Canvas', 70.0, 50.0, 1300.00, '2024-02-01', '2024-03-15'),
('Floral Dreams', 'David Moore', 2016, 'Acrylic', 60.0, 80.0, 1800.00, '2024-03-20', '2024-04-25'),
('Seaside Serenity', 'Jessica Adams', 2021, 'Watercolor', 45.0, 60.0, 850.00, '2024-05-05', '2024-06-15'),
('Winter Whisper', 'Edward Carter', 2018, 'Oil on Canvas', 75.0, 55.0, 1400.00, '2024-01-20', '2024-02-28'),
('Rustic Charm', 'Sophia Turner', 2019, 'Acrylic', 65.0, 75.0, 1600.00, '2024-03-05', '2024-04-10'),
('Enchanted Forest', 'James Wilson', 2020, 'Watercolor', 50.0, 65.0, 1000.00, '2024-04-25', '2024-06-05'),
('Vibrant Horizon', 'Olivia Martinez', 2022, 'Oil on Canvas', 80.0, 60.0, 2200.00, '2024-02-10', '2024-03-20'),
('Starry Night', 'Henry Thomas', 2017, 'Acrylic', 85.0, 65.0, 1900.00, '2024-03-15', '2024-04-30'),
('Peaceful Meadow', 'Charlotte White', 2023, 'Watercolor', 55.0, 70.0, 1050.00, '2024-05-10', '2024-06-25'),
('Mountain Retreat', 'Ethan Harris', 2016, 'Oil on Canvas', 70.0, 55.0, 1150.00, '2024-01-25', '2024-03-05'),
('Blossom Garden', 'Amelia Clark', 2018, 'Acrylic', 60.0, 80.0, 1700.00, '2024-03-25', '2024-05-01'),
('Ocean Waves', 'Mason Wright', 2019, 'Watercolor', 50.0, 75.0, 950.00, '2024-04-30', '2024-06-10'),
('Dancing Colors', 'Isabella Johnson', 2020, 'Oil on Canvas', 77.0, 58.0, 1350.00, '2024-02-15', '2024-03-31'),
('Autumn Path', 'Liam Roberts', 2021, 'Acrylic', 85.0, 70.0, 2100.00, '2024-02-20', '2024-04-05'),
('Whispering Woods', 'Evelyn Jackson', 2017, 'Watercolor', 60.0, 80.0, 880.00, '2024-05-15', '2024-07-01'),
('Cosmic Journey', 'William King', 2023, 'Oil on Canvas', 70.0, 60.0, 1250.00, '2024-01-30', '2024-03-10'),
('Morning Glory', 'Ava Lee', 2018, 'Acrylic', 75.0, 55.0, 1600.00, '2024-03-30', '2024-05-15'),
('Serenity Lake', 'Noah Wilson', 2019, 'Watercolor', 55.0, 65.0, 970.00, '2024-05-01', '2024-06-20'),
('Glistening Snow', 'Emma Martinez', 2020, 'Oil on Canvas', 68.0, 57.0, 1400.00, '2024-02-05', '2024-03-25'),
('Twilight Reflection', 'Oliver Brown', 2022, 'Acrylic', 80.0, 65.0, 1950.00, '2024-04-10', '2024-05-25'),
('Desert Mirage', 'Sophia Thomas', 2016, 'Watercolor', 50.0, 70.0, 850.00, '2024-06-05', '2024-07-20'),
('Urban Rhythm', 'Jacob White', 2017, 'Oil on Canvas', 73.0, 55.0, 1300.00, '2024-01-15', '2024-02-28'),
('Lush Greenery', 'Mia Harris', 2021, 'Acrylic', 90.0, 70.0, 2200.00, '2024-03-20', '2024-05-05'),
('Crystal Waters', 'Lucas Clark', 2018, 'Watercolor', 60.0, 75.0, 960.00, '2024-05-10', '2024-06-30'),
('Radiant Sunset', 'Charlotte Wright', 2019, 'Oil on Canvas', 78.0, 60.0, 1500.00, '2024-02-25', '2024-04-10'),
('Eternal Spring', 'Logan Martinez', 2020, 'Acrylic', 85.0, 65.0, 1800.00, '2024-04-15', '2024-06-05'),
('Nostalgic Streets', 'Aiden Roberts', 2022, 'Watercolor', 55.0, 70.0, 1100.00, '2024-05-20', '2024-07-10'),
('Harmony in Blue', 'Harper Lee', 2023, 'Oil on Canvas', 70.0, 55.0, 1200.00, '2024-03-05', '2024-04-20');