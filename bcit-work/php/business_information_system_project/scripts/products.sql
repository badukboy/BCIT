DROP TABLE IF EXISTS products;
CREATE TABLE products 
(
`id` varchar(3) NOT NULL,
`productname` varchar(80),
`quantityonhand` varchar(4),
`reorderpoint` varchar(4),
`reorderquantity` varchar(4),
`supplieraccountno` varchar(3),
`status` varchar(1),
	PRIMARY KEY (`id`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

INSERT INTO products(id, productname, quantityonhand, reorderpoint, reorderquantity, supplieraccountno, status) 
	VALUES ('001', 'EasyBake oven', '90', '10', '100', '001', 'A');
INSERT INTO products(id, productname, quantityonhand, reorderpoint, reorderquantity, supplieraccountno, status) 
	VALUES ('002', 'EasyBlend blender', '56', '5', '75', '002', 'A');
INSERT INTO products(id, productname, quantityonhand, reorderpoint, reorderquantity, supplieraccountno, status) 
	VALUES ('003', 'EasyCut butchers knife', '62', '1', '100', '003', 'A');
INSERT INTO products(id, productname, quantityonhand, reorderpoint, reorderquantity, supplieraccountno, status) 
	VALUES ('004', 'Wash-ington washing machine', '712', '1000', '100', '004', 'A');
INSERT INTO products(id, productname, quantityonhand, reorderpoint, reorderquantity, supplieraccountno, status) 
	VALUES ('005', 'NukeMyLeftovers microwave', '59', '5', '80', '005', 'D');
INSERT INTO products(id, productname, quantityonhand, reorderpoint, reorderquantity, supplieraccountno, status) 
	VALUES ('006', 'IceMan fridge', '6', '5', '10', '006', 'A');
INSERT INTO products(id, productname, quantityonhand, reorderpoint, reorderquantity, supplieraccountno, status) 
	VALUES ('007', 'IceBoy mini fridge', '46', '40', '50', '007', 'A');
INSERT INTO products(id, productname, quantityonhand, reorderpoint, reorderquantity, supplieraccountno, status) 
	VALUES ('008', 'UnblockMe toilet plunger', '512', '100', '1000', '008', 'D');
INSERT INTO products(id, productname, quantityonhand, reorderpoint, reorderquantity, supplieraccountno, status) 
	VALUES ('009', 'StopLooking! shower curtain', '321', '100', '400', '009', 'A');
INSERT INTO products(id, productname, quantityonhand, reorderpoint, reorderquantity, supplieraccountno, status) 
	VALUES ('010', 'BeerMe bar stool', '29', '5', '50', '010', 'D');
INSERT INTO products(id, productname, quantityonhand, reorderpoint, reorderquantity, supplieraccountno, status) 
	VALUES ('011', 'BeerMe glass pitcher', '691', '610', '1000', '011', 'A');
INSERT INTO products(id, productname, quantityonhand, reorderpoint, reorderquantity, supplieraccountno, status) 
	VALUES ('012', 'BeerMe genuine keg', '4', '1', '5', '012', 'A');