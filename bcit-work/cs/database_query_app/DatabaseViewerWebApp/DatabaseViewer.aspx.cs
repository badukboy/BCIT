using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Data.Odbc;

namespace DatabaseViewerWebApp
{
    public partial class DatabaseViewer : System.Web.UI.Page
    {
        protected void Page_Load(object sender, EventArgs e)
        {
            if (Session["Logged"].Equals("No"))
            {
            }
            else
            {
                labelLoginInfo.Text = "Logged in as: " + (string)Session["User"];
            }
        }

        protected void ButtonSubmit_Click(object sender, EventArgs e)
        {
            /* Set up communication to the database */
            string myConnection = "DSN=myAccess";               
            OdbcConnection myConn = new OdbcConnection(myConnection);       

            labelStatus.Text = "Processing...";
            string myQuery = textBoxInput.Text;
            int numOfColumns = 0;

            OdbcCommand myOdbcCommand = new OdbcCommand(myQuery);
            myOdbcCommand.Connection = myConn;
            myConn.Open();

            OdbcDataReader reader;
            textBoxOutput.Text = "";

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
                if (reader.GetName(i).Length <= 7)
                {
                    textBoxOutput.Text += reader.GetName(i) + "\t\t";
                }
                else
                {
                    textBoxOutput.Text += reader.GetName(i) + "\t";
                }
            }

            textBoxOutput.Text += "\n";

            /* Output the actual data during the first read through */
            for (int i = 0; i < numOfColumns; i++)
            {
                try
                {
                    if (reader.GetString(i).Length <= 7)
                    {
                        textBoxOutput.Text += reader.GetString(i) + "\t\t";
                    }
                    else
                    {
                        textBoxOutput.Text += reader.GetString(i) + "\t";
                    }
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

            textBoxOutput.Text += "\n";

            /* Output the remaining rows of data */
            while (reader.Read())
            {
                for (int i = 0; i < numOfColumns; i++)
                {
                    if (reader.GetString(i).Length <= 7)
                    {
                        textBoxOutput.Text += reader.GetString(i) + "\t\t";
                    }
                    else
                    {
                        textBoxOutput.Text += reader.GetString(i) + "\t";
                    }
                }

                textBoxOutput.Text += "\n";
            }

            labelStatus.Text = "SQL query statement processed!";
     
            myOdbcCommand.Connection.Close();
        }

        protected void buttonClear_Click(object sender, EventArgs e)
        {
            textBoxInput.Text  = "";
            textBoxOutput.Text = "";
            labelStatus.Text = "Awaiting SQL command...";
        }
    }
}