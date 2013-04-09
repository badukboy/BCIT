package a00800403.jms.ui;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

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
import javax.swing.JSpinner;

/**
 * RentalAgreementFrame.java
 * 
 * @author Kevin Csapko, A00800403
 */
public class RentalAgreementFrame extends JFrame
{
	/**
	 * Serial verison UID.
	 */
	private static final long serialVersionUID = 1L;
	
	/**
	 * Main content pane.
	 */
	private JPanel contentPane;
	
	/**
	 * Customer first name.
	 */
	private JTextField fieldFirstName;
	
	/**
	 * Customer last name.
	 */
	private JTextField fieldLastName;
	
	/**
	 * Customer credit card number.
	 */
	private JTextField fieldCreditCard;
	
	/**
	 * Customer address.
	 */
	private JTextField fieldAddress;
	
	/**
	 * Customer phone number.
	 */
	private JTextField fieldPhoneNumber;
	
	/**
	 * Current date.
	 */
	private JTextField fieldDate;
	
	/**
	 * Rental fee per day.
	 */
	private JTextField fieldDailyFee;
	
	/**
	 * Total rental fee.
	 */
	private JTextField fieldTotalFee;
	
	/**
	 * Clear all Customer Information fields.
	 */
	private JButton btnClear;
	
	/**
	 * Creates a new Customer object based on Customer Information fields.
	 */
	private JButton btnSave;
	
	/**
	 * Closes the current frame.
	 */
	private JButton btnClose;

	/**
	 * Launch the application.
	 */
	public RentalAgreementFrame()
	{		
		setTitle("Rental Agreement Dialog");
		setResizable(false);
		setDefaultCloseOperation(RentalAgreementFrame.HIDE_ON_CLOSE);
		setSize(500, 475);
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
		contentPane.setLayout(new MigLayout("", "[645.00,grow]", "[200.00,grow][200.00,grow][200.00]"));
		
		/* Customer Information panel */
		JPanel panelCustomerInformation = new JPanel();
		panelCustomerInformation.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "Customer Information", TitledBorder.LEADING, TitledBorder.TOP, null, null));
		contentPane.add(panelCustomerInformation, "cell 0 0,grow");
		panelCustomerInformation.setLayout(new MigLayout("", "[90.00][grow][][]", "[][][][][][][grow]"));
		
		JLabel lblFirstName = new JLabel("First Name:");
		panelCustomerInformation.add(lblFirstName, "cell 0 0,alignx trailing");
		
		fieldFirstName = new JTextField();
		panelCustomerInformation.add(fieldFirstName, "cell 1 0 3 1,growx");
		fieldFirstName.setColumns(10);
		
		JLabel lblLastName = new JLabel("Last Name:");
		panelCustomerInformation.add(lblLastName, "cell 0 1,alignx trailing");
		
		fieldLastName = new JTextField();
		fieldLastName.setColumns(10);
		panelCustomerInformation.add(fieldLastName, "cell 1 1 3 1,growx");
		
		JLabel lblCreditCard = new JLabel("Credit Card #:");
		panelCustomerInformation.add(lblCreditCard, "cell 0 2,alignx trailing");
		
		fieldCreditCard = new JTextField();
		fieldCreditCard.setColumns(10);
		panelCustomerInformation.add(fieldCreditCard, "cell 1 2 3 1,growx");
		
		JLabel lblAddress = new JLabel("Address:");
		panelCustomerInformation.add(lblAddress, "cell 0 3,alignx trailing");
		
		fieldAddress = new JTextField();
		fieldAddress.setColumns(10);
		panelCustomerInformation.add(fieldAddress, "cell 1 3 3 1,growx");
		
		JLabel lblPhoneNumber = new JLabel("Phone Number:");
		panelCustomerInformation.add(lblPhoneNumber, "cell 0 4,alignx trailing");
		
		fieldPhoneNumber = new JTextField();
		fieldPhoneNumber.setColumns(10);
		panelCustomerInformation.add(fieldPhoneNumber, "cell 1 4 3 1,growx");
		
		btnClear = new JButton("Clear");
		panelCustomerInformation.add(btnClear, "cell 2 5");
		
		btnSave = new JButton("Save");
		panelCustomerInformation.add(btnSave, "cell 3 5");
		
		/* Rental Information panel */
		JPanel panelRentalInformation = new JPanel();
		panelRentalInformation.setBorder(new TitledBorder(null, "Rental Information", TitledBorder.LEADING, TitledBorder.TOP, null, null));
		contentPane.add(panelRentalInformation, "cell 0 1,grow");
		panelRentalInformation.setLayout(new MigLayout("", "[90.00][130.00][grow]", "[][][][][][grow]"));
		
		JLabel lblDate = new JLabel("Date:");
		panelRentalInformation.add(lblDate, "cell 0 0,alignx trailing");
		
		fieldDate = new JTextField();
		fieldDate.setEditable(false);
		panelRentalInformation.add(fieldDate, "cell 1 0,growx");
		fieldDate.setColumns(10);
		
		JLabel lblItem = new JLabel("Item:");
		panelRentalInformation.add(lblItem, "cell 0 1,alignx trailing");
		
		JComboBox<Object> fieldItem = new JComboBox<Object>();
		panelRentalInformation.add(fieldItem, "cell 1 1 2 1,growx");
		
		JLabel lblNumOfDays = new JLabel("# of Days:");
		panelRentalInformation.add(lblNumOfDays, "cell 0 2,alignx trailing");
		
		JSpinner fieldNumOfDays = new JSpinner();
		panelRentalInformation.add(fieldNumOfDays, "cell 1 2,growx");
		
		JLabel lblDailyFee = new JLabel("Daily Fee:");
		panelRentalInformation.add(lblDailyFee, "cell 0 3,alignx trailing");
		
		fieldDailyFee = new JTextField();
		panelRentalInformation.add(fieldDailyFee, "cell 1 3,growx");
		fieldDailyFee.setColumns(10);
		
		JLabel lblTotalFee = new JLabel("Total Fee:");
		panelRentalInformation.add(lblTotalFee, "cell 0 4,alignx trailing");
		
		fieldTotalFee = new JTextField();
		fieldTotalFee.setEditable(false);
		panelRentalInformation.add(fieldTotalFee, "cell 1 4,growx");
		fieldTotalFee.setColumns(10);
		
		btnClose = new JButton("Close");
		contentPane.add(btnClose, "cell 0 2,alignx right,aligny top");
	}

	/**
	 * Generate events.
	 */
	public void attachActions()
	{
		btnClear.addActionListener(new ActionListener()
		{
			/**
			 * Clears all fields within the Customer Information panel.
			 */
			public void actionPerformed(ActionEvent ae)
			{
				fieldFirstName.setText(null);
				fieldLastName.setText(null);
				fieldCreditCard.setText(null);
				fieldAddress.setText(null);
				fieldPhoneNumber.setText(null);
			}
		});
		
		btnSave.addActionListener(new ActionListener()
		{
			/**
			 * Creates a new Customer object based on the input and saves it
			 * to the RentalAgreement object.
			 */
			public void actionPerformed(ActionEvent ae)
			{
				// TODO
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
