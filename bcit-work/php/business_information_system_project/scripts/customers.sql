DROP TABLE IF EXISTS customers;
CREATE TABLE customers 
(
`id` varchar(3) NOT NULL,
`surname` varchar(80),
`firstname` varchar(80),
`status` varchar(1),
	PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO customers(id, surname, firstname, status) 
	VALUES ('001', 'Tiller', 'Ted', 'A');
INSERT INTO customers(id, surname, firstname, status) 
	VALUES ('002', 'Simpson', 'Homer', 'D');
INSERT INTO customers(id, surname, firstname, status) 
	VALUES ('003', 'Einstein', 'Albert', 'D');
INSERT INTO customers(id, surname, firstname, status) 
	VALUES ('004', 'Gerber', 'Fred', 'A');
INSERT INTO customers(id, surname, firstname, status) 
	VALUES ('005', 'Biller', 'Bed', 'A');
INSERT INTO customers(id, surname, firstname, status) 
	VALUES ('006', 'Ziller', 'Zed', 'A');
INSERT INTO customers(id, surname, firstname, status) 
	VALUES ('007', 'Simpson', 'OJ', 'A');
INSERT INTO customers(id, surname, firstname, status) 
	VALUES ('008', 'Briller', 'Brad', 'A');
INSERT INTO customers(id, surname, firstname, status) 
	VALUES ('009', 'Griller', 'Greg', 'D');
INSERT INTO customers(id, surname, firstname, status) 
	VALUES ('010', 'Cosner', 'Kevin', 'A');
INSERT INTO customers(id, surname, firstname, status) 
	VALUES ('011', 'Gein', 'Ed', 'D');
INSERT INTO customers(id, surname, firstname, status) 
	VALUES ('012', 'Lincoln', 'Abraham', 'A');