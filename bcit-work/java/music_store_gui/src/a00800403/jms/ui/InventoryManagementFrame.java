package a00800403.jms.ui;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import net.miginfocom.swing.MigLayout;
import javax.swing.border.TitledBorder;
import javax.swing.UIManager;
import javax.swing.JLabel;
import javax.swing.JComboBox;
import javax.swing.JTextField;
import javax.swing.JButton;

import a00800403.jms.data.MusicalInstrument;

/**
 * InventoryManagementFrame.java
 * 
 * @author Kevin Csapko, A00800403
 */
public class InventoryManagementFrame extends JFrame
{
	/**
	 * Serial version UID.
	 */
	private static final long serialVersionUID = 1L;
	
	/**
	 * Main content pane.
	 */
	private JPanel contentPane;
	
	/**
	 * Product description.
	 */
	private JTextField fieldDescription;
	
	/**
	 * Product stock code (SKU).
	 */
	private JTextField fieldStockCode;
	
	/**
	 * Amount of the product in stock.
	 */
	private JTextField fieldQuantityInStock;
	
	/**
	 * Amount of the product sold.
	 */
	private JTextField fieldQuantitySold;
	
	/**
	 * Purchasing price of the product.
	 */
	private JTextField fieldPurchasePrice;
	
	/**
	 * Selling price of the product.
	 */
	private JTextField fieldSellingPrice;
	
	/**
	 * Number of such products rented.
	 */
	private JTextField fieldNumberRented;
	
	/**
	 * Creates/updates a new/existing product.
	 */
	private JButton btnSave;
	
	/**
	 * Closes the frame.
	 */
	private JButton btnClose;

	/**
	 * Launch the application.
	 */
	public InventoryManagementFrame()
	{
		setTitle("Inventory Management Dialog");
		setDefaultCloseOperation(JFrame.HIDE_ON_CLOSE);
		setSize(500, 375);
		setLocationRelativeTo(null);
		setResizable(false);
		
		buildUI();
		attachActions();
	}
	
	/**
	 * Create the frame.
	 */
	public void buildUI()
	{
		/* Content pane */
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(new MigLayout("", "[645.00,grow]", "[200.00,grow][200.00,grow]"));
		
		/* Inventory Item panel */
		JPanel panelInventoryItem = new JPanel();
		panelInventoryItem.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "Inventory Item", TitledBorder.LEADING, TitledBorder.TOP, null, null));
		contentPane.add(panelInventoryItem, "cell 0 0,grow");
		panelInventoryItem.setLayout(new MigLayout("", "[90.00][grow][]", "[][][][][][][][][][grow]"));
		
		JLabel lblDescription = new JLabel("Description:");
		panelInventoryItem.add(lblDescription, "cell 0 0,alignx trailing");
		
		fieldDescription = new JTextField();
		panelInventoryItem.add(fieldDescription, "cell 1 0 3 1,growx");
		fieldDescription.setColumns(10);
		
		JLabel lblStockCode = new JLabel("Stock Code:");
		panelInventoryItem.add(lblStockCode, "cell 0 1,alignx trailing");
		
		fieldStockCode = new JTextField();
		fieldStockCode.setColumns(10);
		panelInventoryItem.add(fieldStockCode, "cell 1 1 3 1,growx");
		
		JLabel lblQuantityInStock = new JLabel("Quantity in Stock:");
		panelInventoryItem.add(lblQuantityInStock, "cell 0 2,alignx trailing");
		
		fieldQuantityInStock = new JTextField();
		fieldQuantityInStock.setColumns(10);
		panelInventoryItem.add(fieldQuantityInStock, "cell 1 2 3 1,growx");
		
		JLabel lblQuantitySold = new JLabel("Quantity Sold:");
		panelInventoryItem.add(lblQuantitySold, "cell 0 3,alignx trailing");
		
		fieldQuantitySold = new JTextField();
		fieldQuantitySold.setColumns(10);
		panelInventoryItem.add(fieldQuantitySold, "cell 1 3 3 1,growx");
		
		JLabel lblPurchasePrice = new JLabel("Purchase Price:");
		panelInventoryItem.add(lblPurchasePrice, "cell 0 4,alignx trailing");
		
		fieldPurchasePrice = new JTextField();
		fieldPurchasePrice.setColumns(10);
		panelInventoryItem.add(fieldPurchasePrice, "cell 1 4 3 1,growx");
		
		JLabel lblSellingPrice = new JLabel("Selling Price:");
		panelInventoryItem.add(lblSellingPrice, "cell 0 5,alignx trailing");
		
		fieldSellingPrice = new JTextField();
		fieldSellingPrice.setColumns(10);
		panelInventoryItem.add(fieldSellingPrice, "cell 1 5 3 1,growx");
		
		JLabel lblNumberRented = new JLabel("Number Rented:");
		panelInventoryItem.add(lblNumberRented, "cell 0 6,alignx trailing");
		
		fieldNumberRented = new JTextField();
		fieldNumberRented.setColumns(10);
		panelInventoryItem.add(fieldNumberRented, "cell 1 6 3 1,growx");
		
		JLabel lblSelectItem = new JLabel("Select Item:");
		panelInventoryItem.add(lblSelectItem, "cell 0 7,alignx trailing");
		
		JComboBox<Object> comboBox = new JComboBox<Object>();
		panelInventoryItem.add(comboBox, "cell 1 7,growx");
		
		btnSave = new JButton("Save");
		panelInventoryItem.add(btnSave, "cell 2 8");
		
		btnClose = new JButton("Close");
		contentPane.add(btnClose, "cell 0 1,alignx right,aligny top");
	}
	
	/**
	 * Generate events.
	 */
	public void attachActions()
	{
		btnSave.addActionListener(new ActionListener()
		{
			/**
			 * Creates or updates a new or existing product.
			 */
			public void actionPerformed(ActionEvent ae)
			{
				MusicalInstrument instrument = new MusicalInstrument(
						fieldDescription.getText(),
						fieldStockCode.getText(),
						Double.parseDouble(fieldPurchasePrice.getText()),
						Double.parseDouble(fieldSellingPrice.getText()));
			}
		});
		
		btnClose.addActionListener(new ActionListener()
		{
			/**
			 * Closes the current frame.
			 */
			public void actionPerformed(ActionEvent ae)
			{
				setVisible(false);
			}
		});
	}
}
