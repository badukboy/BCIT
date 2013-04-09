DROP TABLE IF EXISTS orders;
CREATE TABLE orders 
(
`id` varchar(3) NOT NULL,
`vendorid` varchar(3),
`description` varchar(150),
`date` varchar(10),
`status` varchar(1),
        PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO orders(id, vendorid, description, date, status) 
	VALUES ('001','002', '2 EasyBlend blenders', '02/06/2013', 'A');
INSERT INTO orders(id, vendorid, description, date, status) 
	VALUES ('002','006', '58 Wash-ington washing machines', '02/22/2013', 'A');
INSERT INTO orders(id, vendorid, description, date, status) 
	VALUES ('003','008', 'Assorted No Name pots and pans', '02/14/2013', 'A');
INSERT INTO orders(id, vendorid, description, date, status) 
	VALUES ('004','009', '200 light fixtures', '02/21/2013', 'A');
INSERT INTO orders(id, vendorid, description, date, status) 
	VALUES ('005','010', '600 flower pots', '02/19/2013', 'A');
INSERT INTO orders(id, vendorid, description, date, status) 
	VALUES ('006','001', '4 sets of Cuisinart knives', '02/09/2013', 'A');
INSERT INTO orders(id, vendorid, description, date, status) 
	VALUES ('007','004', '50 glass pitchers', '03/09/2013', 'A');
INSERT INTO orders(id, vendorid, description, date, status) 
	VALUES ('008','002', '1 NukeMyLeftovers microwave', '04/20/2013', 'A');
INSERT INTO orders(id, vendorid, description, date, status)  
	VALUES ('009','001', '7 EasyBake ovens', '02/27/2013', 'A');
INSERT INTO orders(id, vendorid, description, date, status) 
	VALUES ('010','005', '342 extension cords', '02/27/2013', 'A');
INSERT INTO orders(id, vendorid, description, date, status) 
	VALUES ('011','001', '3 cutting boards', '03/08/2013', 'A');
INSERT INTO orders(id, vendorid, description, date, status)  
	VALUES ('012','003', '1 nail gun, 1 bitcher knife, 1 chainsaw, and rubber gloves', '04/05/2013', 'A');