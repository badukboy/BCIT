package a00800403.jms.ui;

import java.awt.Event;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;

import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.KeyStroke;
import javax.swing.ListModel;
import javax.swing.border.EmptyBorder;
import net.miginfocom.swing.MigLayout;
import javax.swing.border.TitledBorder;
import javax.swing.UIManager;
import javax.swing.JLabel;
import javax.swing.JComboBox;
import java.awt.Font;
import javax.swing.JTextField;
import javax.swing.JButton;
import javax.swing.border.LineBorder;
import java.awt.Color;
import javax.swing.JList;

import a00800403.jms.Driver;
import a00800403.jms.data.MusicalInstrument;
import a00800403.jms.util.InputReader;

/**
 * JMSFrame.java
 * 
 * @author Kevin Csapko, A00800403
 */
public class JMSFrame extends JFrame
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
	 * Application exit menu item.
	 */
	private JMenuItem itemExit;
	
	/**
	 * Display the rental dialog.
	 */
	private JMenuItem itemRental;
	
	/**
	 * Display the inventory dialog.
	 */
	private JMenuItem itemInventory;
	
	/**
	 * Display a credit reel.
	 */
	private JMenuItem itemAbout;
	
	/**
	 * Amount of the selected item to purchase/rent.
	 */
	private JTextField fieldQuantity;
	
	/**
	 * Total sales in purchases.
	 */
	private JTextField fieldSalesTotal;
	
	/**
	 * Total sales in rentals.
	 */
	private JTextField fieldRentalsTotal;
	
	/**
	 * Combined total sales in purchases and rentals.
	 */
	private JTextField fieldFinalSales;

	/**
	 * Launch the application.
	 */
	public JMSFrame()
	{
		setTitle("Java Music Store");
		setDefaultCloseOperation(JMSFrame.EXIT_ON_CLOSE);
		setSize(650, 650);
		setLocationRelativeTo(null);
		
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
		contentPane.setLayout(new MigLayout("", "[645.00,grow]", "[80.00][200.00][200.00][grow]"));
		
		/* Menu */
		JMenuBar menuBar = new JMenuBar();
		setJMenuBar(menuBar);
		
		/* File menu */
		JMenu menuFile = new JMenu("File"); 
		menuFile.setMnemonic('F');
		menuBar.add(menuFile);
		
		/* File > Save Data menu item */
		JMenuItem itemSaveData = new JMenuItem("Save Data");
		itemSaveData.setMnemonic('S');
		itemSaveData.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_S, Event.CTRL_MASK));
		menuFile.add(itemSaveData);
		
		menuFile.addSeparator();
		
		/* File > Exit menu item */
		itemExit = new JMenuItem("Exit");
		itemExit.setMnemonic('x');
		itemExit.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_X, Event.CTRL_MASK));
		menuFile.add(itemExit);
		
		/* Manage menu */
		JMenu menuManage = new JMenu("Manage"); 
		menuManage.setMnemonic('M');
		menuBar.add(menuManage);
		
		/* Manage > Rental menu item */
		itemRental = new JMenuItem("Rental");
		itemRental.setMnemonic('R');
		itemRental.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_R, Event.CTRL_MASK));
		menuManage.add(itemRental);
		
		/* Manage > Inventory menu item */
		itemInventory = new JMenuItem("Inventory");
		itemInventory.setMnemonic('I');
		itemInventory.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_I, Event.CTRL_MASK));
		menuManage.add(itemInventory);
		
		/* Help menu */
		JMenu menuHelp = new JMenu("Help"); 
		menuHelp.setMnemonic('H');
		menuBar.add(menuHelp);
		
		/* Help > About menu item */
		itemAbout = new JMenuItem("About");
		itemAbout.setMnemonic('A');
		itemAbout.setAccelerator(KeyStroke.getKeyStroke(KeyEvent.VK_A, Event.CTRL_MASK));
		menuHelp.add(itemAbout);
		
		/* Selected Items panel */
		JPanel panelSelectedItems = new JPanel();
		panelSelectedItems.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "Selected Items", TitledBorder.LEADING, TitledBorder.TOP, null, null));
		contentPane.add(panelSelectedItems, "cell 0 0,grow");
		panelSelectedItems.setLayout(new MigLayout("", "[][175.00,grow][20.00,grow][][20.00,grow][][100.00,grow][20.00,grow][100.00,grow]", "[50.00]"));
		
		JLabel lblItem = new JLabel("Item:");
		panelSelectedItems.add(lblItem, "cell 0 0,alignx trailing");
		
		JComboBox<Object> comboBox = new JComboBox<Object>(Driver.instruments.toArray());
		panelSelectedItems.add(comboBox, "cell 1 0,growx");
		
		JLabel lblSellingPrice = new JLabel("$0.00");
		lblSellingPrice.setFont(lblSellingPrice.getFont().deriveFont(lblSellingPrice.getFont().getStyle() | Font.BOLD));
		panelSelectedItems.add(lblSellingPrice, "cell 3 0");
		
		JLabel lblQty = new JLabel("QTY:");
		panelSelectedItems.add(lblQty, "cell 5 0,alignx trailing");
		
		fieldQuantity = new JTextField();
		panelSelectedItems.add(fieldQuantity, "cell 6 0,growx");
	    fieldQuantity.setColumns(10);
		
		JButton btnAdd = new JButton("Add");
		panelSelectedItems.add(btnAdd, "cell 8 0,growx");
		
		/* Purchased Items panel */
		JPanel panelPurchasedItems = new JPanel();
		panelPurchasedItems.setBorder(new TitledBorder(null, "Purchased Items", TitledBorder.LEADING, TitledBorder.TOP, null, null));
		contentPane.add(panelPurchasedItems, "cell 0 1,grow");
		panelPurchasedItems.setLayout(new MigLayout("", "[450.00,grow][10.00][grow]", "[140.00,grow][grow]"));
		
		JTextArea listPurchasedItems = new JTextArea();
		listPurchasedItems.setBorder(new LineBorder(Color.GRAY));
		panelPurchasedItems.add(listPurchasedItems, "cell 0 0 1 2,grow");
		
		JLabel lblSalesTotal = new JLabel("SALES TOTAL:");
		lblSalesTotal.setFont(lblSalesTotal.getFont().deriveFont(lblSalesTotal.getFont().getStyle() | Font.BOLD));
		panelPurchasedItems.add(lblSalesTotal, "cell 2 0,aligny bottom");
		
		fieldSalesTotal = new JTextField();
		fieldSalesTotal.setEditable(false);
		panelPurchasedItems.add(fieldSalesTotal, "cell 2 1,growx,aligny bottom");
		fieldSalesTotal.setColumns(10);
		fieldSalesTotal.setBorder(new LineBorder(Color.GRAY));
		
		/* Rental Agreements panel */
		JPanel panelRentalAgreements = new JPanel();
		panelRentalAgreements.setBorder(new TitledBorder(null, "Rental Agreements", TitledBorder.LEADING, TitledBorder.TOP, null, null));
		contentPane.add(panelRentalAgreements, "cell 0 2,grow");
		panelRentalAgreements.setLayout(new MigLayout("", "[450.00,grow][10.00][grow]", "[140.00,grow][grow]"));
		
		JList<Object> listRentalAgreements = new JList<Object>();
		listRentalAgreements.setBorder(new LineBorder(Color.GRAY));
		panelRentalAgreements.add(listRentalAgreements, "cell 0 0 1 2,grow");
		
		JLabel lblRentalsTotal = new JLabel("RENTALS TOTAL:");
		lblRentalsTotal.setFont(lblSalesTotal.getFont().deriveFont(lblSalesTotal.getFont().getStyle() | Font.BOLD));
		panelRentalAgreements.add(lblRentalsTotal, "cell 2 0,aligny bottom");
		
		fieldRentalsTotal = new JTextField();
		fieldRentalsTotal.setEditable(false);
		panelRentalAgreements.add(fieldRentalsTotal, "cell 2 1,growx,aligny bottom");
		fieldRentalsTotal.setColumns(10);
		fieldRentalsTotal.setBorder(new LineBorder(Color.GRAY));
		
		/* Purchase Summary panel */
		JPanel panelPurchaseSummary = new JPanel();
		panelPurchaseSummary.setBorder(new TitledBorder(null, "Purchase Summary", TitledBorder.LEADING, TitledBorder.TOP, null, null));
		contentPane.add(panelPurchaseSummary, "cell 0 3,grow");
		panelPurchaseSummary.setLayout(new MigLayout("", "[200.00,grow][grow]", "[][]"));
		
		JLabel lblFinalSales = new JLabel("FINAL SALES:");
		lblFinalSales.setFont(lblFinalSales.getFont().deriveFont(lblFinalSales.getFont().getStyle() | Font.BOLD));
		panelPurchaseSummary.add(lblFinalSales, "cell 1 0 2 1");
		
		fieldFinalSales = new JTextField();
		fieldFinalSales.setEditable(false);
		panelPurchaseSummary.add(fieldFinalSales, "cell 1 1,growx,aligny top");
		fieldFinalSales.setColumns(10);
		fieldFinalSales.setBorder(new LineBorder(Color.GRAY));
	}
	
	/**
	 * Generate events.
	 */
	public void attachActions()
	{
		itemExit.addActionListener(new ActionListener()
		{
			/**
			 * Allows the user to exit the application.
			 */
			public void actionPerformed(ActionEvent ae)
			{
				shutDown();
			}
		});
		
		itemRental.addActionListener(new ActionListener()
		{
			/**
			 * Launches the Rental Agreement Dialog frame.
			 */
			public void actionPerformed(ActionEvent ae)
			{
				RentalAgreementFrame RAFrame = new RentalAgreementFrame();
				RAFrame.setVisible(true);	
			}
		});
		
		itemInventory.addActionListener(new ActionListener()
		{
			/**
			 * Launches the Inventory Management Dialog frame.
			 */
			public void actionPerformed(ActionEvent ae)
			{
				InventoryManagementFrame IMFrame = new InventoryManagementFrame();
				IMFrame.setVisible(true);
			}
		});
		
		itemAbout.addActionListener(new ActionListener()
		{
			/**
			 * Displays an informative dialog box.
			 */
			public void actionPerformed(ActionEvent ae)
			{
				aboutDialog();
			}
		});
	}
	
	/**
	 * Displays an informative dialog box.
	 */
	public void aboutDialog()
	{
		JOptionPane.showMessageDialog(this, "COMP2526 Assignment 2\n" +
				"by Kevin Csapko, A00800403", "About", JOptionPane.INFORMATION_MESSAGE);
	}
	
	/**
	 * Shuts down the application.
	 */
	public void shutDown()
	{
		System.exit(0);
	}
}
