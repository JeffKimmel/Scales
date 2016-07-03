Use Windows.pkg
Use DFClient.pkg
Open daireports

Deferred_View Activate_oTrucks for ;
Object oTrucks is a dbView

    Set Border_Style to Border_Thick
    Set Size to 180 300
    Set Location to 2 2
    Procedure ImportReportFile
        String sReportName sLink sOrder sJunk
        Direct_Input "C:\WebApps\DashboardReports.txt"
        While (not(SeqEof))
            Read sReportName
            Read sOrder
            Read sLink
            Readln sJunk
            Clear DAIReports
            Move sReportName to DAIReports.ReportName
            Find gt DAIReports by Index.1
            If (sReportName ne DAIReports.ReportName) Begin
                Clear DAIReports
                Lock
            End
            Else Begin
                Reread DAIReports    
            End
            
                Move sReportName to DAIReports.ReportName
                Move sLink to DAIReports.DashboardLink
                Move sOrder to DAIReports.ReportTabOrder
                Move "NewDash" to DAIReports.ReportType
                SaveRecord DAIReports
            Unlock
        Loop
        Close_Output
    End_Procedure
    
    Object oButton1 is a Button
        Set Size to 14 126
        Set Location to 109 48
        Set Label to 'oButton1'
    
        // fires when the button is clicked
        Procedure OnClick
            Send ImportReportFile
        End_Procedure
    
    End_Object

Cd_End_Object
