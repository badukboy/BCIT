using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Data.Odbc;

/**
 * Database Viewer application.
 */
namespace MyWindowsFormsApplication
{
    /**
     * Form event handlers.
     */
    public partial class DatabaseViewer : Form
    {
        /**
         * CONSTRUCTOR: Sets up the DatabaseViewer object.
         */
        public DatabaseViewer()
        {
            InitializeComponent();
        }

        /**
         * Application loaded.
         */
        private void Form1_Load(object sender, EventArgs e)
        {
        }

        /**
         * Submit button pressed.
         */
        private void submitButton_Click(object sender, EventArgs e)
        {
            /* Clear data view prior to handing new data */
            gridViewDatabase.Columns.Clear();                  

            /* Connect to the database */
            string myConnection = "DSN=myAccess";               
            OdbcConnection myConn = new OdbcConnection(myConnection);       

            labelStatus.Text = "Processing...";
            string myQuery = textBoxInput.Text;
            int numOfColumns = 0;

            /* Set up communication to the database */
            OdbcCommand myOdbcCommand = new OdbcCommand(myQuery);
            myOdbcCommand.Connection = myConn;
            myConn.Open();
            OdbcDataReader reader;

            /* Non-query statements (CREATE TABLE, INSERT, DELETE, etc.) */
            if (radioButtonNonQuery.Checked)
            {
                myOdbcCommand.ExecuteNonQuery();

                labelStatus.Text = "SQL non-query statement processed!";
            }

            /* Query statements (SELECT, FROM, JOIN, WHERE, etc.) */
            if (radioButtonQuery.Checked)
            {
                /* Try to read the database */
                try
                {
                    reader = myOdbcCommand.ExecuteReader();
                }
                catch (InvalidOperationException ioe)
                {
                    labelStatus.Text = "ERROR: Invalid input (InvalidOperationException) -- No input detected.";
                    Console.WriteLine(ioe.ToString());

                    return;
                }
                catch (OdbcException oe)
                {
                    labelStatus.Text = "ERROR: Invalid input (OdbcException) -- You are either accessing non-existent data or your syntax is wrong.";
                    Console.WriteLine(oe.ToString());

                    return;
                }

                numOfColumns = reader.FieldCount;

                /* Read first row of data */
                reader.Read();

                /* Output the column names during the first read through */
                for (int i = 0; i < numOfColumns; i++)
                {
                    gridViewDatabase.Columns.Add(reader.GetName(i), reader.GetName(i));
                }

                /* Output the actual data during the first read through */
                for (int i = 0; i < numOfColumns; i++)
                {
                    try
                    {
                        gridViewDatabase.Rows.Add(reader.GetString(i), reader.GetString(++i), reader.GetString(++i));
                    }
                    catch (InvalidOperationException ioe)
                    {
                        labelStatus.Text = "ERROR: Invalid input (InvalidOperationException) -- Perhaps you are attempting to access non-existent data?";
                        Console.WriteLine(ioe.ToString());

                        return;
                    }
                    catch (IndexOutOfRangeException ioore)
                    {
                        labelStatus.Text = "ERROR: Out of range (IndexOutOfRangeException)";
                        Console.WriteLine(ioore.ToString());

                        return;
                    }
                }

                /* Output the remaining rows of data */
                while (reader.Read())
                {
                    for (int i = 0; i < numOfColumns; i++)
                    {
                        gridViewDatabase.Rows.Add(reader.GetString(i), reader.GetString(++i), reader.GetString(++i));
                    }
                }

                labelStatus.Text = "SQL query statement processed!";
            }

            myOdbcCommand.Connection.Close();
        }

        /**
         * SELECT syntax shortcut button pressed.
         */
        private void buttonInsertSelect_Click(object sender, EventArgs e)
        {
            textBoxInput.Text += "SELECT ";
        }

        /**
         * FROM syntax shortcut button pressed.
         */
        private void buttonInsertFrom_Click(object sender, EventArgs e)
        {
            textBoxInput.Text += "FROM ";
        }

        /**
         * WHERE syntax shortcut button pressed.
         */ 
        private void buttonInsertWhere_Click(object sender, EventArgs e)
        {
            textBoxInput.Text += "WHERE ";
        }

        /**
         * JOIN syntax shortcut button pressed.
         */
        private void buttonInsertJoin_Click(object sender, EventArgs e)
        {
            textBoxInput.Text += "JOIN ";
        }

        /**
         * Clear input button pressed.
         */ 
        private void buttonClear_Click(object sender, EventArgs e)
        {
            gridViewDatabase.Columns.Clear();
            textBoxInput.Text = null;
            labelStatus.Text = "Awaiting SQL statement...";
        }
    }
}
