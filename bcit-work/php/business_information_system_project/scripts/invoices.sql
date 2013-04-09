DROP TABLE IF EXISTS invoices;
CREATE TABLE invoices 
(
`id` varchar(3) NOT NULL,
`customer` varchar(3),
`description` varchar(150),
`date` varchar(10),
`status` varchar(1),
	PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO invoices(id, customer, description, date, status) 
	VALUES ('001', '010', 'Invoice to Kevin Cosner for 600 flower pots', '02/28/2013', 'A');
INSERT INTO invoices(id, customer, description, date, status) 
	VALUES ('002', '010', 'Invoice to Kevin Cosner for 200 light fixtures', '02/28/2013', 'A');
INSERT INTO invoices(id, customer, description, date, status) 
	VALUES ('003', '010', 'Invoice to Kevin Cosner for 1 nail gun, 1 butcher knife, 1 chainsaw, and rubber gloves', '03/06/2013', 'D');
INSERT INTO invoices(id, customer, description, date, status) 
	VALUES ('004', '009', 'Invoice to Griller Greg for 342 extension cords', '02/13/2013', 'A');
INSERT INTO invoices(id, customer, description, date, status) 
	VALUES ('005', '007', 'Invoice to OJ Simpson for 1 NukeMyLeftovers microwave', '05/07/2013', 'A');
INSERT INTO invoices(id, customer, description, date, status) 
	VALUES ('006', '012', 'Invoice to Abraham Lincoln for 7 EasyBake ovens', '03/01/2013', 'A');
INSERT INTO invoices(id, customer, description, date, status) 
	VALUES ('007', '007', 'Invoice to OJ Simpson for 4 sets of Cuisinart knives', '04/05/2013', 'A');
INSERT INTO invoices(id, customer, description, date, status) 
	VALUES ('008', '007', 'Invoice to OJ Simpson for 3 cutting boards', '02/11/2013', 'A');
INSERT INTO invoices(id, customer, description, date, status) 
	VALUES ('009', '011', 'Invoice to Ed Gein for assorted No Name pots and pans', '04/06/2013', 'D');
INSERT INTO invoices(id, customer, description, date, status) 
	VALUES ('010', '004', 'Invoice to Ted Tiller for 2 EasyBlend blenders', '01/27/2013', 'A');
INSERT INTO invoices(id, customer, description, date, status) 
	VALUES ('011', '001', 'Invoice to Kevin Cosner for 50 glass pitchers', '03/03/2013', 'A');
INSERT INTO invoices(id, customer, description, date, status) 
	VALUES ('012', '010', 'Ted', '03/01/2013', 'D');