<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="DatabaseViewer.aspx.cs" Inherits="DatabaseViewerWebApp.DatabaseViewer" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title></title>
    <style type="text/css">
        .auto-style1 {
            font-size: x-large;
        }
    </style>
</head>
<body>
    <form id="form1" runat="server">
    <div style="font-family: Arial, Helvetica, sans-serif">
    
        <strong><span class="auto-style1">DATABASE VIEWER APPLICATION</span></strong><br />
        <asp:Label ID="labelLoginInfo" runat="server" Text="Logged in as: null"></asp:Label>
        <br />
        <br />
        SQL Statement&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:TextBox ID="textBoxInput" runat="server" Width="277px"></asp:TextBox>
        <asp:Button ID="buttonSubmit" runat="server" OnClick="ButtonSubmit_Click" Text="Submit" />
        <asp:Button ID="buttonClear" runat="server" OnClick="buttonClear_Click" Text="Clear" />
        <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:TextBox ID="textBoxOutput" runat="server" Height="129px" TextMode="MultiLine" Width="385px"></asp:TextBox>
        <br />
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
        <asp:Label ID="labelStatus" runat="server" style="font-size: x-small" Text="Awaiting SQL command..."></asp:Label>
        <br />
    
    </div>
    </form>
</body>
</html>
