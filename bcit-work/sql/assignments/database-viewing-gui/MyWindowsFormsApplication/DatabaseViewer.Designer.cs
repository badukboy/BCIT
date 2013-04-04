namespace MyWindowsFormsApplication
{
    partial class DatabaseViewer
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.labelInput = new System.Windows.Forms.Label();
            this.textBoxInput = new System.Windows.Forms.TextBox();
            this.buttonSubmit = new System.Windows.Forms.Button();
            this.gridViewDatabase = new System.Windows.Forms.DataGridView();
            this.buttonInsertSelect = new System.Windows.Forms.Button();
            this.buttonInsertFrom = new System.Windows.Forms.Button();
            this.buttonInsertJoin = new System.Windows.Forms.Button();
            this.buttonInsertWhere = new System.Windows.Forms.Button();
            this.buttonClear = new System.Windows.Forms.Button();
            this.labelStatus = new System.Windows.Forms.Label();
            this.groupBoxSyntax = new System.Windows.Forms.GroupBox();
            this.groupBoxActions = new System.Windows.Forms.GroupBox();
            this.radioButtonNonQuery = new System.Windows.Forms.RadioButton();
            this.radioButtonQuery = new System.Windows.Forms.RadioButton();
            ((System.ComponentModel.ISupportInitialize)(this.gridViewDatabase)).BeginInit();
            this.groupBoxSyntax.SuspendLayout();
            this.groupBoxActions.SuspendLayout();
            this.SuspendLayout();
            // 
            // labelInput
            // 
            this.labelInput.AutoSize = true;
            this.labelInput.Location = new System.Drawing.Point(13, 13);
            this.labelInput.Name = "labelInput";
            this.labelInput.Size = new System.Drawing.Size(79, 13);
            this.labelInput.TabIndex = 0;
            this.labelInput.Text = "SQL Statement";
            // 
            // textBoxInput
            // 
            this.textBoxInput.Location = new System.Drawing.Point(98, 10);
            this.textBoxInput.Name = "textBoxInput";
            this.textBoxInput.Size = new System.Drawing.Size(400, 20);
            this.textBoxInput.TabIndex = 1;
            // 
            // buttonSubmit
            // 
            this.buttonSubmit.Location = new System.Drawing.Point(88, 19);
            this.buttonSubmit.Name = "buttonSubmit";
            this.buttonSubmit.Size = new System.Drawing.Size(188, 61);
            this.buttonSubmit.TabIndex = 2;
            this.buttonSubmit.Text = "Submit";
            this.buttonSubmit.UseVisualStyleBackColor = true;
            this.buttonSubmit.Click += new System.EventHandler(this.submitButton_Click);
            // 
            // gridViewDatabase
            // 
            this.gridViewDatabase.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.gridViewDatabase.Location = new System.Drawing.Point(16, 142);
            this.gridViewDatabase.Name = "gridViewDatabase";
            this.gridViewDatabase.Size = new System.Drawing.Size(626, 156);
            this.gridViewDatabase.TabIndex = 3;
            // 
            // buttonInsertSelect
            // 
            this.buttonInsertSelect.Location = new System.Drawing.Point(6, 19);
            this.buttonInsertSelect.Name = "buttonInsertSelect";
            this.buttonInsertSelect.Size = new System.Drawing.Size(76, 61);
            this.buttonInsertSelect.TabIndex = 4;
            this.buttonInsertSelect.Text = "SELECT";
            this.buttonInsertSelect.UseVisualStyleBackColor = true;
            this.buttonInsertSelect.Click += new System.EventHandler(this.buttonInsertSelect_Click);
            // 
            // buttonInsertFrom
            // 
            this.buttonInsertFrom.Location = new System.Drawing.Point(88, 19);
            this.buttonInsertFrom.Name = "buttonInsertFrom";
            this.buttonInsertFrom.Size = new System.Drawing.Size(76, 61);
            this.buttonInsertFrom.TabIndex = 5;
            this.buttonInsertFrom.Text = "FROM";
            this.buttonInsertFrom.UseVisualStyleBackColor = true;
            this.buttonInsertFrom.Click += new System.EventHandler(this.buttonInsertFrom_Click);
            // 
            // buttonInsertJoin
            // 
            this.buttonInsertJoin.Location = new System.Drawing.Point(252, 19);
            this.buttonInsertJoin.Name = "buttonInsertJoin";
            this.buttonInsertJoin.Size = new System.Drawing.Size(76, 61);
            this.buttonInsertJoin.TabIndex = 6;
            this.buttonInsertJoin.Text = "JOIN";
            this.buttonInsertJoin.UseVisualStyleBackColor = true;
            this.buttonInsertJoin.Click += new System.EventHandler(this.buttonInsertJoin_Click);
            // 
            // buttonInsertWhere
            // 
            this.buttonInsertWhere.Location = new System.Drawing.Point(170, 19);
            this.buttonInsertWhere.Name = "buttonInsertWhere";
            this.buttonInsertWhere.Size = new System.Drawing.Size(76, 61);
            this.buttonInsertWhere.TabIndex = 7;
            this.buttonInsertWhere.Text = "WHERE";
            this.buttonInsertWhere.UseVisualStyleBackColor = true;
            this.buttonInsertWhere.Click += new System.EventHandler(this.buttonInsertWhere_Click);
            // 
            // buttonClear
            // 
            this.buttonClear.Location = new System.Drawing.Point(6, 19);
            this.buttonClear.Name = "buttonClear";
            this.buttonClear.Size = new System.Drawing.Size(76, 61);
            this.buttonClear.TabIndex = 8;
            this.buttonClear.Text = "Clear";
            this.buttonClear.UseVisualStyleBackColor = true;
            this.buttonClear.Click += new System.EventHandler(this.buttonClear_Click);
            // 
            // labelStatus
            // 
            this.labelStatus.AutoSize = true;
            this.labelStatus.ImageAlign = System.Drawing.ContentAlignment.MiddleRight;
            this.labelStatus.Location = new System.Drawing.Point(12, 309);
            this.labelStatus.Name = "labelStatus";
            this.labelStatus.Size = new System.Drawing.Size(129, 13);
            this.labelStatus.TabIndex = 9;
            this.labelStatus.Text = "Awaiting SQL statement...";
            this.labelStatus.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // groupBoxSyntax
            // 
            this.groupBoxSyntax.Controls.Add(this.buttonInsertSelect);
            this.groupBoxSyntax.Controls.Add(this.buttonInsertFrom);
            this.groupBoxSyntax.Controls.Add(this.buttonInsertWhere);
            this.groupBoxSyntax.Controls.Add(this.buttonInsertJoin);
            this.groupBoxSyntax.Location = new System.Drawing.Point(16, 48);
            this.groupBoxSyntax.Name = "groupBoxSyntax";
            this.groupBoxSyntax.Size = new System.Drawing.Size(338, 88);
            this.groupBoxSyntax.TabIndex = 10;
            this.groupBoxSyntax.TabStop = false;
            this.groupBoxSyntax.Text = "Quick Syntax Selection";
            // 
            // groupBoxActions
            // 
            this.groupBoxActions.Controls.Add(this.buttonClear);
            this.groupBoxActions.Controls.Add(this.buttonSubmit);
            this.groupBoxActions.Location = new System.Drawing.Point(360, 48);
            this.groupBoxActions.Name = "groupBoxActions";
            this.groupBoxActions.Size = new System.Drawing.Size(282, 88);
            this.groupBoxActions.TabIndex = 11;
            this.groupBoxActions.TabStop = false;
            this.groupBoxActions.Text = "Actions";
            // 
            // radioButtonNonQuery
            // 
            this.radioButtonNonQuery.AutoSize = true;
            this.radioButtonNonQuery.Checked = true;
            this.radioButtonNonQuery.Location = new System.Drawing.Point(504, 11);
            this.radioButtonNonQuery.Name = "radioButtonNonQuery";
            this.radioButtonNonQuery.Size = new System.Drawing.Size(76, 17);
            this.radioButtonNonQuery.TabIndex = 12;
            this.radioButtonNonQuery.TabStop = true;
            this.radioButtonNonQuery.Text = "Non-Query";
            this.radioButtonNonQuery.UseVisualStyleBackColor = true;
            // 
            // radioButtonQuery
            // 
            this.radioButtonQuery.AutoSize = true;
            this.radioButtonQuery.Location = new System.Drawing.Point(585, 11);
            this.radioButtonQuery.Name = "radioButtonQuery";
            this.radioButtonQuery.Size = new System.Drawing.Size(53, 17);
            this.radioButtonQuery.TabIndex = 13;
            this.radioButtonQuery.Text = "Query";
            this.radioButtonQuery.UseVisualStyleBackColor = true;
            // 
            // DatabaseViewer
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(654, 331);
            this.Controls.Add(this.radioButtonQuery);
            this.Controls.Add(this.radioButtonNonQuery);
            this.Controls.Add(this.groupBoxActions);
            this.Controls.Add(this.groupBoxSyntax);
            this.Controls.Add(this.labelStatus);
            this.Controls.Add(this.gridViewDatabase);
            this.Controls.Add(this.textBoxInput);
            this.Controls.Add(this.labelInput);
            this.Name = "DatabaseViewer";
            this.Text = "Database Viewer";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.gridViewDatabase)).EndInit();
            this.groupBoxSyntax.ResumeLayout(false);
            this.groupBoxActions.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label labelInput;
        private System.Windows.Forms.TextBox textBoxInput;
        private System.Windows.Forms.Button buttonSubmit;
        private System.Windows.Forms.DataGridView gridViewDatabase;
        private System.Windows.Forms.Button buttonInsertSelect;
        private System.Windows.Forms.Button buttonInsertFrom;
        private System.Windows.Forms.Button buttonInsertJoin;
        private System.Windows.Forms.Button buttonInsertWhere;
        private System.Windows.Forms.Button buttonClear;
        private System.Windows.Forms.Label labelStatus;
        private System.Windows.Forms.GroupBox groupBoxSyntax;
        private System.Windows.Forms.GroupBox groupBoxActions;
        private System.Windows.Forms.RadioButton radioButtonNonQuery;
        private System.Windows.Forms.RadioButton radioButtonQuery;

    }
}

