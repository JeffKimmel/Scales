//*************************************************************************
//*                                                                       *
//*  Confidential Trade Secret.                                           *
//*  Copyright (c) 1997-2008 Mertech Data Systems Inc, Miami Florida      *
//*  All rights reserved.                                                 *
//*  DataFlex is a registered trademark of Data Access Corporation.       *
//*                                                                       *
//*************************************************************************
USE UI
USE SEQ_CHNL.PKG

#REM -----------------------------------------------
#REM Mertech Data Systems Inc. - www.mertechdata.com
#REM mertech.inc Version 3.0.11
#REM -----------------------------------------------

//=============================================================================
//Defines and Replaces
//====================

//Extended Table Attributes
Define DF_FILE_PRIMARY_KEY                          For (DF_FILE_RECORD_REREAD+1)
Define DF_FILE_NUMBER_INVERSE_KEYS                  For (DF_FILE_RECORD_REREAD+3)

//=============================================================================
/// @Name        DF_FILE_SET_MODE
/// @Description Allows switching between set-oriented and record oriented fetch modes.
///
/// If the DF_FILE_SET_MODE is set to TRUE, the driver will fetch a set of records
/// for each find.  If DF_FILE_SET_MODE is FALSE, the driver will fetch only one
/// record at a time.  The benefits of switching between modes were explained
/// at the beginning of this chapter in more detail.  This attribute is also
/// specified in the .INT file during migration through Flex2SQL (see INT File Options).
///
/// Note: Turning off set mode can have a significant detrimental impact on performance
///
/// @Assumptions
/// @Status      Public
/// @Drivers     All
/// @VersionNote
/// @See
///
/// @Syntax Set_Attribute DF_FILE_SET_MODE of <FileNo|FileName> to DFTRUE | DFFALSE
/// @Param  FileNumber            Number of the file
/// @Param  FileName              Name of the file
/// @Param  FieldNumber           Number of the field
/// @Example
/// string sDatabaseName
/// open ORDERHEA
/// integer file_handle
/// move 30 to file_handle
/// Get_Attribute DF_FILE_DATABASENAME of 30 to SDatabaseName
/// showln "SdatabaseName: " Sdatabasename
Define DF_FILE_SET_MODE                             For (DF_FILE_RECORD_REREAD+5)

//=============================================================================
/// @Name        DF_FILE_DATABASENAME
/// @Description Returns the name of the database where the table was created.
///
/// @Assumptions
/// @Status      Public
/// @Drivers     SQLFlex, MySQLFlex, PGFlex
/// @VersionNote
/// @See
///
/// @Syntax Get_Attribute DF_FILE_DATABASENAME of <FileNo|FileName> to sDatabase
/// @Param  FileNumber            Number of the file
/// @Param  FileName              Name of the file
/// @Param  FieldNumber           Number of the field
/// @Param  sDatabase             Variable receiving database name
/// @Example
/// string sDatabaseName
/// open ORDERHEA
/// integer file_handle
/// move 30 to file_handle
/// Get_Attribute DF_FILE_DATABASENAME of 30 to SDatabaseName
/// showln "SdatabaseName: " Sdatabasename
Define DF_FILE_DATABASENAME                         For (DF_FILE_RECORD_REREAD+6)

Define DF_FILE_MAX_ROWS                             For (DF_FILE_RECORD_REREAD+7)

//=============================================================================
/// @Name        DF_FILE_TABLE_NAME
/// @Description Use this attribute to set or get the name of the SQL table
/// corresponding to the specified file name or number.
///
/// @Assumptions
/// @Status      Public
/// @Drivers     All
/// @VersionNote
/// @See
///
/// @Syntax Get_Attribute DF_FILE_TABLE_NAME of <FileNo|FileName> to sTable
/// @Syntax Set_Attribute DF_FILE_TABLE_NAME of <FileNo|FileName> to sTable
/// @Param  FileNumber            Number of the file
/// @Param  FileName              Name of the file
/// @Param  FieldNumber           Number of the field
/// @Param  sDatabase             Variable holding/receiving table name
/// @Example
/// string sDatabaseName
/// string sTableName
/// open ORDERHEA
/// integer file_handle
/// move 30 to file_handle
/// Get_Attribute DF_FILE_TABLE_NAME of 30 to sTableName
/// showln "sTableName: " sTableName
Define DF_FILE_TABLE_NAME                           For (DF_FILE_RECORD_REREAD+8)

//=============================================================================
/// @Name        DF_FILE_CACHE_MODE
/// @Description Activates or deactivates the local cache for set-oriented searches.
///
/// Through the DF_FILE_CACHE_MODE attribute, we can activate or deactivate the
/// local cache. When the cache is active in a set-oriented search, a fixed
/// number of records are pre-fetched and kept in the local cache. If a record
/// is not found in the local cache, a new set is fetched.
///
/// Note: turning off the cache can have significant detrimental effects on performance.
///
/// @Assumptions
/// @Status      Public
/// @Drivers     All
/// @VersionNote
/// @See
///
/// @Syntax Set_Attribute DF_FILE_CACHE_MODE of <FileNo|FileName> to DFTRUE|DFFALSE
/// @Syntax Get_Attribute DF_FILE_CACHE_MODE of <FileNo|FileName> to vBool
/// @Param  FileNumber            Number of the file
/// @Param  FileName              Name of the file
/// @Param  FieldNumber           Number of the field
/// @Param  vBool                 Variable receiving cache mode
/// @Example
/// #INCLUDE MERTECH.INC
/// string sFileCache
/// open ORDERHEA
/// integer file_handle
/// move 30 to file_handle
/// Set_Attribute DF_FILE_CACHE_MODE of 30 to DFTRUE
/// Get_Attribute DF_FILE_CACHE_MODE of 30 to sFileCache
/// showln "sFileCache: " sFileCache
Define DF_FILE_CACHE_MODE                           For (DF_FILE_RECORD_REREAD+9)

Define DF_FILE_STORAGE_BASE                         For (DF_FILE_RECORD_REREAD+10)

//=============================================================================
/// @Name        DF_FILE_STATIC
/// @Description DF_FILE_STATIC is a Boolean that when set to DFTRUE loads all
/// records of a file in memory to improve performance.
///
/// When we activate the static mode of a file, the driver loads all the records
/// of a table in the local cache. All searches are then done on this file
/// in memory and the actual table is not accessed.  The driver does not allow
/// editing of a table in static mode.  This is a very useful feature especially
/// when a table contains configuration or static information used in
/// calculations, (i.e., Tax Rate tables, etc.) By keeping this file locally
/// in memory, network round trips are saved, thus resulting in significant
/// performance improvements. This attribute is also useful for batch
/// processes that make extensive table IO requests for reading static information.
///
/// Note: For very large static files, this attribute should be set to DFFALSE.
///
/// @Assumptions
/// @Status      Public
/// @Drivers     All
/// @VersionNote
/// @See
///
/// @Syntax Set_Attribute DF_FILE_STATIC of <FileNo|FileName> to DFTRUE|DFFALSE
/// @Param  FileNumber            Number of the file
/// @Param  FileName              Name of the file
/// @Param  FieldNumber           Number of the field
/// @Example
/// #INCLUDE MERTECH.INC
/// string sFileCache
/// open ORDERHEA
/// integer file_handle
/// move 30 to file_handle
/// Set_Attribute DF_FILE_CACHE_MODE of 30 to DFTRUE
/// Get_Attribute DF_FILE_CACHE_MODE of 30 to sFileCache
/// showln "sFileCache: " sFileCache
Define DF_FILE_STATIC                               For (DF_FILE_RECORD_REREAD+11)

Define DF_FILE_SERVER_NAME                          For (DF_FILE_RECORD_REREAD+12)
Define DF_FETCH_FIELD_COUNT                         For (DF_FILE_RECORD_REREAD+13)

//=============================================================================
/// @Name        DF_FILE_TABLESPACE_NAME
/// @Description Gets or sets the table space where table data is created.
///
/// @Assumptions
/// @Status      Public
/// @Drivers     ORAFlex
/// @VersionNote
/// @See         DF_FILE_TABLESPACE_NAME DF_FILE_INDEXTABLESPACE_NAME
///
/// @Syntax Get_Attribute DF_FILE_NAME_SPACE of <FileNo|FileName> to sTableSpace
/// @Syntax Set_Attribute DF_FILE_NAME_SPACE of <FileNo|FileName> to sTableSpace
/// @Param  FileNumber            Number of the file
/// @Param  FileName              Name of the file
/// @Param  FieldNumber           Number of the field
/// @Param  sDatabase             Variable holding/receiving table space name
/// @Example
/// integer liFile liField
/// move 0 to liFile
/// Structure_Start liFile "ORA_DRV"
///     Set_Attribute DF_FILE_TABLESPACE_NAME      of liFile To "USERS"
///     Set_Attribute DF_FILE_INDEXTABLESPACE_NAME of liFile To "INDXS"
///     //
///     Set_Attribute DF_FILE_PHYSICAL_NAME   of liFile to "test.int"
///     //
///     Move 0 to liField
///     Create_Field liFile At liField //CODE
///     Move 1 To liField
///     Set_Attribute DF_FIELD_NAME           of liFile liField To "CODE"
///     Set_Attribute DF_FIELD_TYPE           of liFile liField To DF_BCD
///     Set_Attribute DF_FIELD_LENGTH         of liFile liField To 4
///     //
///     Move 0 to liField
///     Create_Field liFile At liField //DESC
///     Move 2 To liField
///     Set_Attribute DF_FIELD_NAME           of liFile liField To "DESC"
///     Set_Attribute DF_FIELD_TYPE           of liFile liField To DF_ASCII
///     Set_Attribute DF_FIELD_LENGTH         of liFile liField To 20
/// Structure_End liFile DF_STRUCTEND_OPT_NONE "." 0
Define DF_FILE_TABLESPACE_NAME                      For (DF_FILE_RECORD_REREAD+14)

Define DF_FETCH_FIELDNUMBER                         For (DF_FILE_RECORD_REREAD+15)

//=============================================================================
/// @Name        DF_FILE_INDEXTABLESPACE_NAME
/// @Description Gets or sets the table space where indexes are created.
///
/// @Assumptions
/// @Status      Public
/// @Drivers     ORAFlex
/// @VersionNote
/// @See         DF_FILE_TABLESPACE_NAME DF_FILE_INDEXTABLESPACE_NAME
///
/// @Syntax Get_Attribute DF_FILE_DATABASENAME of <FileNo|FileName> to sIndexSpace
/// @Syntax Set_Attribute DF_FILE_DATABASENAME of <FileNo|FileName> to sIndexSpace
/// @Param  FileNumber            Number of the file
/// @Param  FileName              Name of the file
/// @Param  FieldNumber           Number of the field
/// @Param  sDatabase             Variable holding/receiving index table space name
Define DF_FILE_INDEXTABLESPACE_NAME                 For (DF_FILE_RECORD_REREAD+16)

Define DF_FILE_RETRIEVE_RECNUM                      For (DF_FILE_RECORD_REREAD+17)

//=============================================================================
/// @Name        DF_FILE_NAME_SPACE
/// @Description Gets or sets the schema name where the table is created.
///
/// @Assumptions
/// @Status      Public
/// @Drivers     PGFlex
/// @VersionNote
/// @See
///
/// @Syntax Get_Attribute DF_FILE_NAME_SPACE of <FileNo|FileName> to sNameSpace
/// @Syntax Set_Attribute DF_FILE_NAME_SPACE of <FileNo|FileName> to sNameSpace
/// @Param  FileNumber            Number of the file
/// @Param  FileName              Name of the file
/// @Param  FieldNumber           Number of the field
/// @Param  sDatabase             Variable holding/receiving space name
/// @Example
/// open ORDERHEA
/// string vSchema
/// Get_Attribute DF_FILE_NAME_SPACE of ORDERHEA.file_number To vSchema
/// show "Schema is: " vSchema
Define DF_FILE_NAME_SPACE                           For (DF_FILE_RECORD_REREAD+18)

Define DF_FILE_STORAGE_PCTFREE                      For (DF_FILE_RECORD_REREAD+19)
Define DF_FILE_STORAGE_PCTUSED                      For (DF_FILE_RECORD_REREAD+21)
Define DF_FILE_STORAGE_INITIAL                      For (DF_FILE_RECORD_REREAD+23)
Define DF_FILE_STORAGE_NEXT                         For (DF_FILE_RECORD_REREAD+25)
Define DF_FILE_ALLOW_NULL                           For (DF_FILE_RECORD_REREAD+27)

//=============================================================================
/// @Name        DF_FILE_GET_SERVERNAME_FROM_LOGIN
/// @Description Gets or sets if when opening the table the server to use
/// comes from the INT file or from currently logged on to SQL backend.
///
/// If the INT file has the server name in it, the driver will always
/// assume that the table resides on that server, no matter what
/// servers the user has logged in to.
///
/// @Assumptions
/// @Status      Public
/// @Drivers     All
/// @VersionNote
/// @See         DF_FILE_GET_SERVERNAME_FROM_LOGIN DF_FILE_GET_DATABASENAME_FROM_LOGIN DF_FILE_GET_SCHEMANAME_FROM_LOGIN
///
/// @Syntax Get_Attribute DF_FILE_GET_SERVERNAME_FROM_LOGIN of <FileNo|FileName> to bBool
/// @Syntax Set_Attribute DF_FILE_GET_SERVERNAME_FROM_LOGIN of <FileNo|FileName> to DFTRUE|DFFALSE
/// @Param  FileNumber            Number of the file
/// @Param  FileName              Name of the file
/// @Param  FieldNumber           Number of the field
/// @Param  bBool                 Variable receiving DFTRUE or DFFALSE
/// @Example
/// Integer iFile
/// Open "customer.int" as customer
/// Move customer.file_number to iFile
///
/// Structure_Start iFile sMainDriver
///    Set_Attribute DF_FILE_GET_SERVERNAME_FROM_LOGIN   of iFile to 1
///    Set_Attribute DF_FILE_GET_DATABASENAME_FROM_LOGIN of iFile to 1
///    Set_Attribute DF_FILE_GET_SCHEMANAME_FROM_LOGIN   of iFile to 1
/// Structure_End iFile DF_STRUCTEND_OPT_NONE "." 0
Define DF_FILE_GET_SERVERNAME_FROM_LOGIN            For (DF_FILE_RECORD_REREAD+29)

//=============================================================================
/// @Name        DF_FILE_GET_DATABASENAME_FROM_LOGIN
/// @Description Gets or sets if when opening the table the database to use
/// comes from the INT file or from currently logged on to SQL backend.
///
/// If the INT file contains the database name name this will override the
/// user's default database or the database set with SET_DATABASE_NAME.
///
/// @Assumptions
/// @Status      Public
/// @Drivers     All
/// @VersionNote
/// @See         SET_DATABASE_NAME DF_FILE_GET_SERVERNAME_FROM_LOGIN DF_FILE_GET_DATABASENAME_FROM_LOGIN DF_FILE_GET_SCHEMANAME_FROM_LOGIN
///
/// @Syntax Get_Attribute DF_FILE_GET_DATABASENAME_FROM_LOGIN of <FileNo|FileName> to bBool
/// @Syntax Set_Attribute DF_FILE_GET_DATABASENAME_FROM_LOGIN of <FileNo|FileName> to DFTRUE|DFFALSE
/// @Param  FileNumber            Number of the file
/// @Param  FileName              Name of the file
/// @Param  FieldNumber           Number of the field
/// @Param  bBool                 Variable receiving DFTRUE or DFFALSE
/// @Example
/// Integer iFile
/// Open "customer.int" as customer
/// Move customer.file_number to iFile
///
/// Structure_Start iFile sMainDriver
///    Set_Attribute DF_FILE_GET_SERVERNAME_FROM_LOGIN   of iFile to 1
///    Set_Attribute DF_FILE_GET_DATABASENAME_FROM_LOGIN of iFile to 1
///    Set_Attribute DF_FILE_GET_SCHEMANAME_FROM_LOGIN   of iFile to 1
/// Structure_End iFile DF_STRUCTEND_OPT_NONE "." 0
Define DF_FILE_GET_DATABASENAME_FROM_LOGIN          For (DF_FILE_RECORD_REREAD+31)

//=============================================================================
/// @Name        DF_FILE_GET_SCHEMANAME_FROM_LOGIN
/// @Description Gets or sets if when opening the table the schema to use
/// comes from the INT file or from currently logged on to SQL backend.
///
/// If the INT file contains the database name name this will override the
/// user's default schema or the schema set with SET_SCHEMA_NAME
/// (SET_NAME_SPACE for PostgreSQL).
///
/// @Assumptions
/// @Status      Public
/// @Drivers     SQLFlex ORAFlex PGFlex
/// @VersionNote
/// @See         SET_SCHEMA_NAME SET_NAME_SPACE DF_FILE_GET_SERVERNAME_FROM_LOGIN DF_FILE_GET_DATABASENAME_FROM_LOGIN DF_FILE_GET_SCHEMANAME_FROM_LOGIN
///
/// @Syntax Get_Attribute DF_FILE_GET_SCHEMANAME_FROM_LOGIN of <FileNo|FileName> to bBool
/// @Syntax Set_Attribute DF_FILE_GET_SCHEMANAME_FROM_LOGIN of <FileNo|FileName> to DFTRUE|DFFALSE
/// @Param  FileNumber            Number of the file
/// @Param  FileName              Name of the file
/// @Param  FieldNumber           Number of the field
/// @Param  bBool                 Variable receiving DFTRUE or DFFALSE
/// @Example
/// Integer iFile
/// Open "customer.int" as customer
/// Move customer.file_number to iFile
///
/// Structure_Start iFile sMainDriver
///    Set_Attribute DF_FILE_GET_SERVERNAME_FROM_LOGIN   of iFile to 1
///    Set_Attribute DF_FILE_GET_DATABASENAME_FROM_LOGIN of iFile to 1
///    Set_Attribute DF_FILE_GET_SCHEMANAME_FROM_LOGIN   of iFile to 1
/// Structure_End iFile DF_STRUCTEND_OPT_NONE "." 0
Define DF_FILE_GET_SCHEMANAME_FROM_LOGIN            For (DF_FILE_RECORD_REREAD+33)

Define DF_FILE_PRESERVE_RECNUM                      For 184
Define DF_FILE_NATIVE_RECORD_LENGTH                 For 194

Define DF_FILE_OEM_TRANSLATION                      For (DF_FILE_RECORD_REREAD+51)
Define DF_FILE_EPOCH_YEAR                           For (DF_FILE_RECORD_REREAD+53)

Define DF_FILE_USE_ROWCOUNT_IN_TRANSACTIONS         For 628
DEfine DF_FILE_ICF_STATUS                           For 630
Define DF_FILE_LOCK_RECORD_STATUS                   For 632
Define DF_FILE_CASING                               For 634

Define DF_FIELD_INVERSE_KEY_NAME                    For (DF_FIELD_NATIVE_LENGTH+1)
Define DF_FIELD_INVERSE_KEY_TYPE                    For (DF_FIELD_NATIVE_LENGTH+2)
Define DF_FIELD_TEXT_SEGMENT_NAME                   For (DF_FIELD_NATIVE_LENGTH+3)
Define DF_FIELD_TEXT_NUM_SEGMENTS                   For (DF_FIELD_NATIVE_LENGTH+4)

//=============================================================================
/// @Name        DF_FIELD_DEFAULT_VALUE
/// @Description This attribute sets the default value of the field on the SQLbackend
/// @Assumptions
/// @Status      Public
/// @Drivers     All
/// @VersionNote
/// @See
///
/// @Syntax Set_Attribute DF_FIELD_DEFAULT_VALUE of <FileNumber|FileName FieldNumber> to <vDefaultVal>
/// @Syntax Get_Attribute DF_FIELD_DEFAULT_VALUE of <FileNumber|FileName FieldNumber> to <vDefaultVal>
/// @Param  FileNumber            Number of the file
/// @Param  FileName              Name of the file
/// @Param  FieldNumber           Number of the field
/// @Param  vDefaultValue         Default value to set/Variable receiving default value
/// @Example
/// open ORDERHEA
/// date dDate dVar
/// move "12/12/2002" to dVar
/// integer file_handle
/// move 30 to file_handle
/// structure_start file_handle "ORA_DRV"
///    Set_Attribute DF_FIELD_DEFAULT_VALUE of file_handle 3 to dVar
/// structure_end file_handle 0
/// Get_Attribute DF_FIELD_DEFAULT_VALUE of 30 3 to dDate
/// showln "dDate: " dDate
Define DF_FIELD_DEFAULT_VALUE                       For (DF_FIELD_NATIVE_LENGTH+5)

Define DF_FIELD_TEXT_LENGTH_SEGMENT                 For (DF_FIELD_NATIVE_LENGTH+6)

//=============================================================================
/// @Name        DF_FIELD_TIME_ON
/// @Description Assign a field to retrieve Time Stamp value from a DATETIME
/// column in a table.
///
/// This option was implemented because some versions of DataFlex do not support
/// DATETIME fields normally supported by SQL databases.
///
/// To use this: Change the type of a date field in your FD to string type,
/// Set the attribute DF_FIELD_TIME_ON of this field to TRUE and
/// recompile your program.
/// @Assumptions
/// @Status      Public
/// @Drivers     All
/// @VersionNote
/// @See
///
/// @Syntax Set_Attribute DF_FIELD_TIME_ON of <FileNumber|FileName FieldNumber> to DFTRUE | DFFALSE
/// @Param  FileNumber            Number of the file
/// @Param  FileName              Name of the file
/// @Param  FieldNumber           Number of the field
/// @Example
/// #INCLUDE MERTECH.INC
/// string sDateTime sDatabaseName
/// open ORDERHEA
/// Set_Attribute DF_FIELD_TIME_ON of 30 3 to dfTrue
/// find GE ORDERHEA by recnum
/// move ORDERHEA.ORDER_DATE to sDateTime
/// showln "sDateTime: " sDateTime
Define DF_FIELD_TIME_ON                             For (DF_FIELD_NATIVE_LENGTH+8)

Define DF_FIELD_NATIVE_NAME                         For (DF_FIELD_NATIVE_LENGTH+9)

//=============================================================================
/// @Name        DF_FIELD_NULL
/// @Description This toggle command enables or disables the ability to
/// accept NULL values in a field.  If set to DFFALSE, the specified column
/// of the table cannot accepts null value.  In the convert database, Flex2SQL
/// defines fields that are part of an index segment to be DF_FIELD_NULL as DFFALSE.
/// Using Structure commands, you are able to change this column attribute.
///
///
/// @Assumptions
/// @Status      Public
/// @Drivers     All
/// @VersionNote
/// @See
///
/// @Syntax Set_Attribute DF_FIELD_NULL of <FileNumber|FileName FieldNumber> to DFTRUE | DFFALSE
/// @Param  FileNumber            Number of the file
/// @Param  FileName              Name of the file
/// @Param  FieldNumber           Number of the field
/// @Example
Define DF_FIELD_NULL                                For (DF_FIELD_NATIVE_LENGTH+10)


//=============================================================================
/// @Name        DF_FIELD_NATIVE_TYPE
/// @Description Specifies the native type (the type on the SQL backend) of a field.
///
/// Can be used in Structure
/// commands to create columns in the table or retrieve the type of a column.
/// During table creation using Structure commands there is no need specify the
/// native type for a column; the driver uses a default data type.
///
/// Note: Please see the types defined in mertech.inc for available options
/// listed under "SQL Server Data Types", "MySQL Data Types", and
/// "Oracle Data Types", "PostgreSQL Data Types".
///
/// @Assumptions
/// @Status      Public
/// @Drivers     All
/// @VersionNote
/// @See
///
/// @Syntax Set_Attribute DF_FIELD_NATIVE_TYPE of <FileNumber|FileName FieldNumber> to <vNativeType>
/// @Syntax Get_Attribute DF_FIELD_NATIVE_TYPE of <FileNumber|FileName FieldNumber> to <vNativeType>
/// @Param  FileNumber            Number of the file
/// @Param  FileName              Name of the file
/// @Param  FieldNumber           Number of the field
/// @Param  vNativeType           Default type to use set/Variable receiving type
/// @Example
/// open ORDERHEA
/// integer liFile liField liFields
/// string  lsFName
/// integer liType liNType liNull
///
/// move ORDERHEA.file_number to liFile
/// Get_Attribute DF_FILE_NUMBER_FIELDS Of liFile to liFields
///
/// showln (pad("FieldName",30)) (pad("Type",10)) (pad("Native Type",15)) (pad("Null",4))
/// For liField From 0 to liFields
///     Get_Attribute DF_FIELD_NAME        of liFile liField to lsFName
///     Get_Attribute DF_FIELD_TYPE        of liFile liField to liType
///     Get_Attribute DF_FIELD_NATIVE_TYPE of liFile liField to liNType
///     Get_Attribute DF_FIELD_NULL        of liFile liField to liNull
///     showln (pad(lsFName,30)) (pad(liType,10)) (pad(liNType,15)) (pad(liNull,4))
/// loop
Define DF_FIELD_NATIVE_TYPE                         For (DF_FIELD_NATIVE_LENGTH+12)
Define DF_FIELD_NATIVE_OFFSET                       For (DF_FIELD_NATIVE_LENGTH+14)
Define DF_FIELD_AUTO_INCREMENT                      For (DF_FIELD_NATIVE_LENGTH+16)
Define DF_FIELD_GENERATE_ALWAYS                     For (DF_FIELD_NATIVE_LENGTH+18)

Define DF_FIELD_SEND_LONG_DATA                      For 702

Define DF_INDEX_NATIVE_CREATED                      For (DF_INDEX_KEY_LENGTH+1)

//=============================================================================
/// @Name        DF_INDEX_NAME
/// @Description DF_INDEX_NAME Contains the name of the native index of the table.
///
/// Through this attribute, the name of the native index is returned. Unlike
/// DataFlex, SQL databases work with named indexes.  Each index number in
/// DataFlex must map to a corresponding named index on the server.
/// Absence of a corresponding native index will result in significant
/// performance degradation.  In case the specified index does not exist
/// in the database, a blank value will be returned. During the creation
/// of a new table or restructuring of existing tables, we can use the
/// command Set_Attribute DF_INDEX_NAME to modify the name of a native index.
///
/// @Assumptions
/// @Status      Public
/// @Drivers     All
/// @VersionNote
/// @See
///
/// @Syntax Get_Attribute DF_INDEX_NAME of <FileNo|FileName> to sIndex
/// @Syntax Set_Attribute DF_INDEX_NAME of <FileNo|FileName> to sIndex
/// @Param  FileNumber            Number of the file
/// @Param  FileName              Name of the file
/// @Param  FieldNumber           Number of the field
/// @Param  sIndex                Variable holding/receiving index name
/// @Example
/// open ORDERHEA
/// integer file_handle
/// move 30 to file_handle
/// Get_Attribute DF_INDEX_NAME of 30 1 to sIndexName
/// showln "sIndexName: " sIndexName
Define DF_INDEX_NAME                                For (DF_INDEX_KEY_LENGTH+2)

//=============================================================================
/// @Name        DF_PRIMARY_KEY
/// @Description DF_PRIMARY_KEY Contains the number of the index that identifies
/// the primary key of the table.
///
/// Through the command Get_Attribute DF_INDEX_PRIMARY_KEY we can recover
/// the number of the index that represents the primary key of the table.
/// During the creation of a new table or restructuring of the primary key
/// ///  of an existing table, one can use the command, Set_Attribute
///  DF_INDEX_PRIMARY_KEY, to modify it.
///
/// @Assumptions
/// @Status      Public
/// @Drivers     All
/// @VersionNote
/// @See
///
/// @Syntax Get_Attribute DF_PRIMARY_KEY of <FileNo|FileName> to vPrimaryKey
/// @Syntax Set_Attribute DF_PRIMARY_KEY of <FileNo|FileName> to vPrimaryKey
/// @Param  FileNumber            Number of the file
/// @Param  FileName              Name of the file
/// @Param  FieldNumber           Number of the field
/// @Param  vPrimaryKey                Variable holding/receiving primary key number
/// @Example
/// integer iPrimaryKey
/// open ORDERHEA
/// integer file_handle
/// move 30 to file_handle
/// Get_Attribute DF_INDEX_PRIMARY_KEY of 30 to iPrimaryKey
/// showln "iPrimaryKey: " iPrimaryKey
/// Set_Attribute DF_INDEX_PRIMARY_KEY of 30 to (iPrimaryKey + 1)
/// Get_Attribute DF_INDEX_PRIMARY_KEY of 30 to iPrimaryKey
/// showln "iPrimaryKey: " iPrimaryKey
Define DF_PRIMARY_KEY                               For (DF_INDEX_KEY_LENGTH+3)

Define DF_INDEX_PRIMARY_KEY                         For (DF_INDEX_KEY_LENGTH+3)

//=============================================================================
/// @Name        DF_INDEX_STATUS
/// @Description DF_INDEX_STATUS contains the status of the native index of the table.
///
/// This is available only for ORAFlex and shows the index STATUS.
/// Oracle has an attribute that describes the index status. This is
/// available on ALL_INDEXES view (there is a column named STATUS). Its
/// value is VALID or not VALID. If it is not VALID, then the index is not useful.
///
/// @Assumptions
/// @Status      Public
/// @Drivers     All
/// @VersionNote
/// @See
///
/// @Syntax Get_Attribute DF_INDEX_STATUS of <FileNo|FileName> to vPrimaryKey
/// @Param  FileNumber            Number of the file
/// @Param  FileName              Name of the file
/// @Param  FieldNumber           Number of the field
/// @Param  vPrimaryKey           Variable receiving the index status
/// @Example
/// string sIndexStatus
/// open ORDERHEA
/// integer file_handle
/// move 30 to file_handle
/// Get_Attribute DF_INDEX_STATUS of 30 1 to sIndexStatus
/// showln "sIndexStatus: " sIndexStatus
Define DF_INDEX_STATUS                              For (DF_INDEX_KEY_LENGTH+4)

Define DF_INDEX_STORAGE_PCTFREE                     For (DF_INDEX_KEY_LENGTH+5)
Define DF_INDEX_UNIQUE                              For (DF_INDEX_KEY_LENGTH+6)
Define DF_INDEX_STORAGE_BASE                        For (DF_INDEX_KEY_LENGTH+7)
Define DF_INDEX_STORAGE_INITIAL                     For (DF_INDEX_KEY_LENGTH+8)
Define DF_INDEX_STORAGE_NEXT                        For (DF_INDEX_KEY_LENGTH+10)
Define DF_INDEX_NATIVE_TYPE                         For (DF_INDEX_KEY_LENGTH+13)
Define DF_INDEX_TABLESPACE                          For (DF_INDEX_KEY_LENGTH+14)

Define DF_FIELD_PROGRAMMATIC_DEFAULT                For 701
Define DF_FIELD_TIME                                For 703
Define DF_FIELD_IS_NULL                             For 704
Define DF_FIELD_IS_LOB                              For 706
Define DF_FIELD_HANDLE_AS_LOB                       For 708
Define DF_FIELD_PARTIAL_OVERLAP                     For 710

Define DF_FILE_NUMBER_SQL_RELATIONS                 For 626
Define DF_SQL_RELATION_COLUMN                       For 716
Define DF_SQL_RELATION_RELATED_SCHEMA               For 717
Define DF_SQL_RELATION_RELATED_TABLE                For 719
Define DF_SQL_RELATION_RELATED_COLUMN               For 721
Define DF_SQL_RELATION_NAME                         For 723
Define DF_SQL_RELATION_STATUS                       For 724
Define DF_SQL_RELATION_DELETE_REF_ACTION            For 726

Define DF_FIELD_OVERLAP_START                       For 728
Define DF_FIELD_OVERLAP_END                         For 730
Define DF_FIELD_OVERLAP_OFFSET_START                For 732
Define DF_FIELD_OVERLAP_OFFSET_END                  For 734


Define DF_FILE_RECNUM_TABLE                         For 1401
Define DF_FILE_PRIMARY_INDEX                        For 1402
Define DF_FILE_RECNUM_NAME                          For 1403

Define DF_FETCH_ALL                                 For -1
Define DF_FETCH_TRUE                                For "TRUE"
Define DF_FETCH_FALSE                               For "FALSE"
Define DF_BIND_ALL_COLUMNS                          For -1

// SQLFlex Lock Type
Define DF_LOCK_TYPE_PAGE                            For 3

// Extended Callback Types
Define DF_MESSAGE_ERROR                             For 9
Define DF_MESSAGE_PROGRESS_STATUS                   For 20
Define DF_MESSAGE_PROGRESS_CONTINUE                 For 21

//Drivers
Define ORAFLEX                                      For "ORA_DRV"
Define SQLFLEX                                      For "SQL_DRV"
Define MDSDB2                                       For "MDS_DB2"
Define MDSPgSQL                                     For "MDSPGSQL"
Define PgFlex                                       For "MDSPGSQL"
Define MDSMySQL                                     For "MDSMYSQL"
Define MySQLFlex                                    For "MDSMYSQL"

// Delimiter for SQL ID objects
Define DB2_ID_DELIM                                 For '"'
Define MYSQL_ID_DELIM                               For "`"
Define ORACLE_ID_DELIM                              For '"'
Define PGSQL_ID_DELIM                               For '"'
Define SQLSERVER_ID_DELIM                           For '"'

// dfStructureEnd Option bits
Define DF_STRUCTEND_OPT_INDEX_ONLY                  For 16    // Internal Use Only
Define DF_STRUCTEND_OPT_FORCE_INVK                  For 32
Define DF_STRUCTEND_OPT_OLD_INVK_NAME               For 64
Define DF_STRUCTEND_OPT_FORCE_NOT_NULL              For 128
Define DF_STRUCTEND_OPT_CREATE_ROWID_TABLE          For 256

//Additional Data Types
Define DF_DATETIME                                  For 7

//Call_Driver Functions
Define CALLDRV_LICENSE_ENVIRONMENT_SET              For 0
Define CALLDRV_ORA_CURRENT_SQL_SERVER               For 6
Define CALLDRV_SQL_ERROR_MESSAGE                    For 14
Define CALLDRV_CURRENT_SQL_SERVER                   For 19
Define CALLDRV_SQL_MAX_CURSORS                      For 26
Define CALLDRV_SQLLOADER_FIELDS_TERM                For 30
Define CALLDRV_CREATE_TABLE_FROM_DAT                For 30
Define CALLDRV_SQLLOADER_DECIMAL_SEP                For 31
Define CALLDRV_CONVERT_DAT_FILE                     For 32
Define CALLDRV_SQLFLEX_MAX_CURSORS                  For 37
Define CALLDRV_NATIVE_OPTIMIZATION                  For 38
Define CALLDRV_GET_RETURNED_COLUMNS                 For 39
Define CALLDRV_GET_RETURNED_ROWS                    For 40
Define CALLDRV_GET_COLUMN_ATTRIBUTE                 For 41
Define CALLDRV_START_TXTGEN_AFTER_RECNUM            For 42
Define CALLDRV_FINISH_TXTGEN_AFTER_RECNUM           For 43
Define CALLDRV_SET_ISOLATION_LEVEL                  For 44
Define CALLDRV_GET_SERVER_CFG                       For 45
Define CALLDRV_SET_SQL_LOCK_TIMEOUT                 For 46
Define CALLDRV_GET_SQL_LOCK_TIMEOUT                 For 47
Define CALLDRV_GET_RESULTS                          For 48
Define CALLDRV_GET_MORE_RESULTS                     For 49
Define CALLDRV_GET_CURRENT_USER_NAME                For 50
Define CALLDRV_OPEN_EMBEDDED_CURSOR                 For 51
Define CALLDRV_CLOSE_EMBEDDED_CURSOR                For 52
Define CALLDRV_SET_CURRENT_EMBEDDED_CURSOR          For 53
Define CALLDRV_GET_CURRENT_EMBEDDED_CURSOR          For 54
Define CALLDRV_SET_MAX_EMBEDDED_CURSOR              For 55
Define CALLDRV_GET_MAX_EMBEDDED_CURSOR              For 56
Define CALLDRV_SQL_TRANSACTION                      For 57
Define CALLDRV_LOCAL_TD_PATH                        For 58
Define CALLDRV_CREATE_DB                            For 59
Define CALLDRV_ESCAPE_STRING                        For 60
Define CALLDRV_SET_PROC_ATTRIBUTE_TYPE              For 61
Define CALLDRV_SQL_REFRESH_CACHE                    For 62
Define CALLDRV_GET_SQL_STMT                         For 63
Define CALLDRV_DIRECT_PATH_LOAD                     For 64

Define CALLDRV_READ_LOB                             For 65
Define CALLDRV_WRITE_LOB                            For 66
Define CALLDRV_APPEND_LOB                           For 67
Define CALLDRV_LENGTH_LOB                           For 68
Define CALLDRV_LOADFROMFILE_LOB                     For 69
Define CALLDRV_ERASE_LOB                            For 70
Define CALLDRV_TRUNCATE_LOB                         For 71
Define CALLDRV_INITIALIZE_SEQUENCE                  For 72
Define CALLDRV_CLIENT_CFG                           For 73
Define CALLDRV_END_SAVERECORD                       For 74
Define CALLDRV_ENABLE_RECONNECT                     For 75
Define CALLDRV_ENUMERATE_SERVER                     For 76
Define CALLDRV_USE_ROWCOUNT_IN_TRANSACTIONS         For 77
Define CALLDRV_USE_DFLEX_DATE_FORMAT                For 78
Define CALLDRV_FORCE_FIELDS_NOT_NULL                For 79
Define CALLDRV_ORA_CREATE_TABLE_FROM_DAT            For 80
Define CALLDRV_MAX_DATA_SIZE                        For 81
Define CALLDRV_CHUNK_SIZE                           For 82
Define CALLDRV_GET_DATA_CHUNK                       For 83
Define CALLDRV_MIRROR_SERVER                        For 84
Define CALLDRV_COPY_DATA                            For 85
Define CALLDRV_SET_SQL_CURSOR_TYPE                  For 86
Define CALLDRV_ICF                                  For 87
Define CALLDRV_CLEAR_INT_CACHE                      For 88
Define CALLDRV_GET_CURRENT_USER_PASSWORD            For 89
Define CALLDRV_FORCE_FIELDS_NULL                    For 90
Define CALLDRV_TRANSACTIONS_ALLOWED                 For 91
Define CALLDRV_SQL_ERROR_MESSAGE2                   For 92
Define CALLDRV_PGSQL_NAME_SPACE                     For 93
Define CALLDRV_EMBEDDED_SQL_TYPE                    For 94
Define CALLDRV_CREATE_INVK_FUNCTIONS                For 95
Define CALLDRV_DEFAULT_FILE_CASING                  For 96
Define CALLDRV_GLOBAL_SETTING                       For 97
Define CALLDRV_RESTRUCTURE_SCRIPT                   For 98
Define CALLDRV_CURRENT_SQL_SERVER_CONNECTION        For 99
Define CALLDRV_100                                  For 100
Define CALLDRV_FILE_STRUCT_DYNAMIC_ONLINE           For 101

// License and environment settings
Define CALLDRV_DRIVER_REVISION                      For 0
Define CALLDRV_COMPANY_NAME                         For 1
Define CALLDRV_SERIAL_NUMBER                        For 2
Define CALLDRV_LICENSED_USERS                       For 3
Define CALLDRV_MAJOR_REVISION                       For 4
Define CALLDRV_VERSION_COMMENTS                     For 5
Define CALLDRV_OLEDB_OEM_TRANSLATION                For 6
Define CALLDRV_SET_DB_PORT                          For 7
Define CALLDRV_GET_DB_PORT                          For 8
Define CALLDRV_SET_DB_SOCKET                        For 9
Define CALLDRV_GET_DB_SOCKET                        For 10
Define CALLDRV_SET_AS_SYSDBA                        For 11
Define CALLDRV_OEM_TRANSLATION_STATE                For 12
Define CALLDRV_TIME_TO_LIC_EXPIRATION               For 13
Define CALLDRV_LICENSE_EXPIRATION_WARN              For 14
Define CALLDRV_LICENSE_PATH                         For 15
Define CALLDRV_AUTO_NUMERIC_REMAPPING               For 16
Define CALLDRV_FORCE_DATE_FORMAT_INIT               For 17
Define CALLDRV_STATIC_TABLE_OPT                     For 18
Define CALLDRV_MAX_OBJECT_NAME_LENGTH               For 19
Define CALLDRV_USE_LAZY_OPEN_MODE                   For 20
Define CALLDRV_SET_CUSTOM_OEM_TO_ANSI               For 21
Define CALLDRV_GET_CUSTOM_OEM_TO_ANSI               For 22

//CALLDRV_ENUMERATE_SERVER_OPTION
Define CALLDRV_ENUMERATE_SERVER_COUNT               For 0
Define CALLDRV_ENUMERATE_SERVER_SERVER              For 1

//CALLDRV_DEFAULT_FILE_CASING
Define FILE_CASING_UPPER                            For 0
Define FILE_CASING_LOWER                            For 1
Define FILE_CASING_KEEP                             For 2

// CALLDRV_GLOBAL_SETTING
Define GLOBAL_SETTING_TABLESPACE_SET                For 0
Define GLOBAL_SETTING_TABLESPACE_GET                For 1
Define GLOBAL_SETTING_INDEX_TABLESPACE_SET          For 2
Define GLOBAL_SETTING_INDEX_TABLESPACE_GET          For 3

// CALLDRV_RESTRUCTURE_SCRIPT
Define CALLDRV_RESTRUCTURE_SCRIPT_ENABLE            For 0
Define CALLDRV_RESTRUCTURE_SCRIPT_DISABLE           For 1
Define CALLDRV_RESTRUCTURE_SCRIPT_GET_CHUNK_SQL     For 2
Define CALLDRV_RESTRUCTURE_SCRIPT_GET_CHUNK_INT     For 3

// DF_SQL_RELATION_STATUS attributes
Define FOREIGN_KEY_NONE                             For -1
Define FOREIGN_KEY_CREATE                           For  0
Define FOREIGN_KEY_ENABLE                           For  1
Define FOREIGN_KEY_DISABLE                          For  2
Define FOREIGN_KEY_DROP                             For  3

// DF_SQL_RELATION_DELETE_REF_ACTION attributes
Define DELETE_REF_NONE                              For 0
Define DELETE_REF_CASCADE                           For 1
Define DELETE_REF_SET_NULL                          For 2
Define DELETE_REF_SET_DEFAULT                       For 3
Define DELETE_REF_RESTRICT                          For 4

//Embedded SQL Cursor Types
Define CALLDRV_ENUMERATE_CURSOR_TYPE_NONE           For 0
Define CALLDRV_ENUMERATE_CURSOR_TYPE_CLIENT         For 1
Define CALLDRV_ENUMERATE_CURSOR_TYPE_SERVER         For 2
Define CALLDRV_ENUMERATE_CURSOR_TYPE_PARAMETERIZED  For 3

//Driver Call Direction
Define CALLDRV_VALUE_GET                            For 0
Define CALLDRV_VALUE_SET                            For 1

//Inverse Key types
Define REGULAR_SEG                                  For -1
Define INVK_CASE_SEG                                For 0
Define INVK_DESC_SEG                                For 1
Define INVK_DESC_AND_CASE_SEG                       For 2

//DB2 Index Types
Define REG_INDEX                                    For 0
Define REV_INDEX                                    For 1
Define CLUST_INDEX                                  For 2
Define REV_CLUST_INDEX                              For 3

//Oracle Procedure Arguments type
Define IS_NONE                                      For 0
Define IS_IN                                        For 1
Define IS_OUT                                       For 2
Define IS_IN_OUT                                    For 3
Define IS_RSET                                      For 4

// SQL_GET_COL Attributes
Define SQL_GET_COL_ATTRIB_SIZE                      For 1
Define SQL_GET_COL_ATTRIB_DECIMALS                  For 2
Define SQL_GET_COL_ATTRIB_LABEL                     For 3
Define SQL_GET_COL_ATTRIB_COLUMN_NAME               For 4
Define SQL_GET_COL_ATTRIB_TABLE_NAME                For 5
Define SQL_GET_COL_ATTRIB_SQLTYPE                   For 6
Define SQL_GET_COL_ATTRIB_NULLABLE                  For 7
Define SQL_GET_COL_ATTRIB_DFTYPE                    For 8
Define SQL_GET_COL_ATTRIB_DATA_LENGTH               For 9

// MySQL Data Types
Define eMySQL_DECIMAL                               For 0
Define eMySQL_TINY                                  For 1
Define eMySQL_SHORT                                 For 2
Define eMySQL_LONG                                  For 3
Define eMySQL_FLOAT                                 For 4
Define eMySQL_DOUBLE                                For 5
Define eMySQL_NULL                                  For 6
Define eMySQL_TIMESTAMP                             For 7
Define eMySQL_LONGLONG                              For 8
Define eMySQL_INT24                                 For 9
Define eMySQL_DATE                                  For 10
Define eMySQL_TIME                                  For 11
Define eMySQL_DATETIME                              For 12
Define eMySQL_YEAR                                  For 13
Define eMySQL_NEWDATE                               For 14
Define eMySQL_BIT                                   For 16
Define eMySQL_NEWDECIMAL                            For 246
Define eMySQL_ENUM                                  For 247
Define eMySQL_SET                                   For 248
Define eMySQL_TINY_BLOB                             For 249
Define eMySQL_MEDIUM_BLOB                           For 250
Define eMySQL_LONG_BLOB                             For 251
Define eMySQL_BLOB                                  For 252
Define eMySQL_VAR_STRING                            For 253
Define eMySQL_STRING                                For 254
Define eMySQL_TINY_TEXT                             For -249
Define eMySQL_MEDIUM_TEXT                           For -250
Define eMySQL_LONG_TEXT                             For -251
Define eMySQL_TEXT                                  For -252

// Oracle Data Types
Define eOracle_VARCHAR2                             For   1
Define eOracle_NUMBER                               For   2
Define eOracle_INT                                  For   3
Define eOracle_FLOAT                                For   4
Define eOracle_STRING                               For   5
Define eOracle_LONG                                 For   8
Define eOracle_ROWID                                For  11
Define eOracle_DATE                                 For  12
Define eOracle_RAW                                  For  23
Define eOracle_LONGRAW                              For  24
Define eOracle_CHAR                                 For  96
Define eOracle_MSLABEL                              For 106
Define eOracle_CLOB                                 For 112
Define eOracle_BLOB                                 For 113

// PostgreSQL Data Types
Define ePgSQL_CIRCLE                                For  718
Define ePgSQL_MONEY                                 For  790
Define ePgSQL_BOOL                                  For   16
Define ePgSQL_BYTEA                                 For   17
Define ePgSQL_CHAR                                  For   18
Define ePgSQL_INT2                                  For   21
Define ePgSQL_INT4                                  For   23
Define ePgSQL_REGPROC                               For   24
Define ePgSQL_TEXT                                  For   25
Define ePgSQL_CITEXT                                For  -25
Define ePgSQL_OID                                   For   26
Define ePgSQL_TID                                   For   27
Define ePgSQL_XID                                   For   28
Define ePgSQL_CID                                   For   29
Define ePgSQL_BPCHAR                                For 1042
Define ePgSQL_VARCHAR                               For 1043
Define ePgSQL_INT8                                  For   20
Define ePgSQL_PATH                                  For  602
Define ePgSQL_FLOAT4                                For  700
Define ePgSQL_FLOAT8                                For  701
Define ePgSQL_ABSTIME                               For  702
Define ePgSQL_RELTIME                               For  703
Define ePgSQL_TINTERVAL                             For  704
Define ePgSQL_POLYGON                               For  604
Define ePgSQL_ACLITEM                               For 1033
Define ePgSQL_MACADDR                               For  829
Define ePgSQL_INET                                  For  869
Define ePgSQL_CIDR                                  For  650
Define ePgSQL_TIMESTAMP                             For 1114
Define ePgSQL_DATE                                  For 1082
Define ePgSQL_TIME                                  For 1083
Define ePgSQL_TIMESTAMPTZ                           For 1184
Define ePgSQL_INTERVAL                              For 1186
Define ePgSQL_NUMERIC                               For 1700
Define ePgSQL_TIMETZ                                For 1266
Define ePgSQL_BIT                                   For 1560
Define ePgSQL_VARBIT                                For 1562
Define ePgSQL_UUID                                  For 2950

// SQL Server Data Types
Define eSQLServer_NA                                For    0
Define eSQLServer_CHAR                              For    1
Define eSQLServer_NUMERIC                           For    2
Define eSQLServer_DECIMAL                           For    3
Define eSQLServer_INT                               For    4
Define eSQLServer_SMALLINT                          For    5
Define eSQLServer_FLOAT                             For    6
Define eSQLServer_REAL                              For    7
Define eSQLServer_DOUBLE                            For    8
Define eSQLServer_DATETIME                          For   11
Define eSQLServer_VARCHAR                           For   12
Define eSQLServer_DATE                              For   40
Define eSQLServer_TIME                              For   41
Define eSQLServer_DATETIME2                         For   42
Define eSQLServer_DATETIMEOFFSET                    For   43
Define eSQLServer_SMALLDATETIME                     For   58
Define eSQLServer_TIMESTAMP                         For   93
Define eSQLServer_HIERARCHYID                       For  128
Define eSQLServer_GEOMETRY                          For  129
Define eSQLServer_GEOGRAPHY                         For  130
Define eSQLServer_TEXT                              For   -1
Define eSQLServer_BINARY                            For   -2
Define eSQLServer_VARBINARY                         For   -3
Define eSQLServer_IMAGE                             For   -4
Define eSQLServer_BIGINT                            For   -5
Define eSQLServer_TINYINT                           For   -6
Define eSQLServer_BIT                               For   -7
Define eSQLServer_NCHAR                             For   -8
Define eSQLServer_NVARCHAR                          For   -9
Define eSQLServer_NTEXT                             For  -10
Define eSQLServer_GUID                              For  -11
Define eSQLServer_VARBINARYMAX                      For  -98
Define eSQLServer_VARCHARMAX                        For  -99
Define eSQLServer_NVARCHARMAX                       For -100
Define eSQLServer_SQLVARIANT                        For -150
Define eSQLServer_XML                               For -370

//=============================================================================
//Error Text
//==========

//=============================================================================
//Define Self if needed
//=====================

#IFDEF SELF
#ELSE
    #REPLACE SELF |VI85  // as of vdf12.0 this is now part of fmac
#ENDIF

//=============================================================================
//Define varibles we need
//=======================

#IFDEF MertechInc_Variables_Defined
#ELSE
    Define MertechInc_Variables_Defined

    Indicator MertechInc_bThereIsBinding

    Integer MertechInc_FileNumber      //Replaces _SAVEFILENUMBER# and FILENUMBER
    Integer MertechInc_iArg            //Replaces _LLONG#
    Integer MertechInc_iCallBack       //Replaces _CALLBACK#
    Integer MertechInc_iCount          //General loop limit integer
    Integer MertechInc_iDecSep         //Holds the decimal seperator
    Integer MertechInc_iFunction       //Replaces _FID#    ??? check is this is need when tidy is complete
    Integer MertechInc_iLoop           //General loop integer
    Integer Mertech_iMySQLParam        //Replaces _ALL_PAR_POS#
    Integer MertechInc_iParamCount     //Replaces _NPAR#
    Integer MertechInc_iRet            //Replaces _RET#
    Integer MertechInc_iSaveCount      //Replaces _NPOS#
    Integer MertechInc_iWork           //General work integer

    String MertechInc_Blank            //Replaces _BLANK#
    String MertechInc_DriverName       //Replaces _DRIVERNAME#
    String MertechInc_sArg1 255        //Replaces _ARG1#
    String MertechInc_sArg2 255        //Replaces _ARG2#
    String MertechInc_sWork 255        //General work string

    String MertechInc_CurrentDriver    //Keep the current driver name
    //Global string are created pre filled with spaces. We need an empty string
    Move "" to MertechInc_Blank
    Move "" to MertechInc_CurrentDriver

    #Replace MertechInc_Invalid_Driver -1
#ENDIF

//=============================================================================
//Use Obsolete Code
//=================

#COMMAND MertechInc_Use_Obsolete_Code
    Define MertechInc_Obsolete_Code
#ENDCOMMAND

#COMMAND MertechInc_Error_Obsolete_Code
    #ERROR 4400 Obsolete code used. Recode or Add statement MertechInc_Use_Obsolete_Code after including Mertech.inc
#ENDCOMMAND

//=============================================================================
//Comment Block Template
//======================

/// @Name <name of command for indexing> (used for documentation)
/// @Description <Short Command description> (used for documentation)
///     The description can be multiple lines, and contain HTML tags,
///     the other tokens will have HTML encoded so we can show stuff like <param1> properly
///     A blank line will automatically be translated into a paragraph break in the documentation,
///     so no need for <br> or <p> tags.
///
/// @Status <Obsolete|Internal|Public> (used for documentation)
/// @Drivers <List of supported drivers : DB2Flex, MySQLFlex, ORAFlex, PgFlex and SQLFlex> (used for documentation)
/// @VersionNote <any change done to the command>
/// @See <list of other commands>
///
/// @Syntax <Syntax of use> (used for documentation)
/// @Param <Parameter(1) description> (used for documentation)
/// @Param <Parameter(n) description> (used for documentation)
/// @DBMS <List of supported databases>
/// @DataFlex <List of supported DataFlex versions>
/// @Usage <Usage example(1)> (used for documentation)
/// @Usage <Usage example(2)> (used for documentation)
///
/// @Example <complete example that shows how the command can be used> (used for documentation)

//=============================================================================
/// @Name        DO_GETFILENUMBER_DRIVERNAME
/// @Description Retrieves the current driver name and or the file number that will be used by the macro commands
/// @Status      Internal Use Only
/// @Drivers     All
/// @VersionNote Last Revised: 2009-07-14 By Ian Smith
///
#COMMAND DO_GETFILENUMBER_DRIVERNAME R .
    //Get file number from parameter
    #IFDEF !1
        MOVE !1 TO MertechInc_FileNumber
    #ELSE
        #IFDEF !1.RECNUM
            #SET Q$ !1.RECNUM
        #ELSE
            #SET Q$ !1.FILE_NUMBER
        #ENDIF
        !A [] $82 |CI!q MertechInc_FileNumber
    #ENDIF

    Send MertechInc_Get_Driver_name
#ENDCOMMAND

//Most commands use DO_GETFILENUMBER_DRIVERNAME so this code was being duplicated
//all the time. It has been moved to this method to remove that duplication.
Procedure MertechInc_Get_Driver_name Global
    //If we have a file number get its driver, else find first loaded Mertech driver
    If MertechInc_FileNumber GT 0 ;
        Get_Attribute DF_FILE_DRIVER of MertechInc_FileNumber to MertechInc_DriverName
    Else Begin
        If (MertechInc_CurrentDriver > "") Move MertechInc_CurrentDriver to MertechInc_DriverName
        Else Begin
            Get_Attribute DF_NUMBER_DRIVERS to MertechInc_iCount
            For MertechInc_iLoop from 1 to MertechInc_iCount
                Get_Attribute DF_DRIVER_NAME of MertechInc_iLoop to MertechInc_DriverName
                Move (UPPERCASE(MertechInc_DriverName)) to MertechInc_DriverName
                If (MertechInc_DriverName EQ ORAFLEX  or MertechInc_DriverName EQ SQLFLEX or MertechInc_DriverName EQ MDSDB2 or ;
                    MertechInc_DriverName EQ MDSPgSQL or MertechInc_DriverName EQ MDSMySQL) Move MertechInc_iCount to MertechInc_iLoop
                Else Move "" to MertechInc_DriverName
            Loop
        End
    End

    //Ensure that we return a valid Mertech driver.
    If (MertechInc_DriverName NE ORAFLEX  and ;
        MertechInc_DriverName NE SQLFLEX  and ;
        MertechInc_DriverName NE MDSDB2   and ;
        MertechInc_DriverName NE MDSPgSQL and ;
        MertechInc_DriverName NE MDSMySQL     ) ;
        Begin

        //Report invalid driver
//        Error 25100 ("Invalid Driver - file" * String(MertechInc_FileNumber))
//        Error 25100 ("Mertech.inc - Not a Mertech driver (file number " * String(MertechInc_FileNumber) * ")")
        Error 25100 ("Mertech.inc - Not a Mertech driver. File" * String(MertechInc_FileNumber) * "Driver" * Trim(MertechInc_DriverName) )

        //Set MertechInc_FileNumber to MertechInc_Invalid_Driver so that the commands can
        //determine if the driver is valid. MertechInc_FileNumber is use instead of
        //MertechInc_DriverName as integer conparisons are quicker than string conparisons
        Move MertechInc_Invalid_Driver to MertechInc_FileNumber
    End
End_Procedure

//=============================================================================
/// @Name        MertechInc_Pre_Size_String
/// @Description Returns a string full of spaces.
/// @Status      Internal
/// @Drivers     n/a
/// @VersionNote Last Revised: 2009-08-12 By Ian Smith
/// @VersionNote Last Revised: 2009-12-02 By Gandalf Hernandez - blockwise fill-up
///
Function MertechInc_Pre_Size_String Global Integer iSize Returns String
   Local String sWork
   Local Integer iBlocks iRemainder

   If (iSize <= 1) Begin
      // marcelo 06/28/2000 implemented logic to avoid VDF 7 crashing problems
      #IFDEF FMAC_VERSION
          If FMAC_VERSION eq 7 Move 1000 to iSize
          Else Move 16384 to iSize
      #ELSE
          Move 16384 to iSize
      #ENDIF
   End

   // Build the string in blocks of 32, to speed things up
   // If the string is less than 32 bytes, just fill it up regularly
   Move (iSize / 32) to iBlocks
   Move (Mod(iSize, 32)) to iRemainder

   If (iBlocks > 0) Begin
      Move (Repeat("                                ", iBlocks)) to sWork
      Move (Append (sWork, (Repeat(" ", iRemainder)))) to sWork
   End
   Else Move (Repeat(" ", iSize)) to sWork

   Function_Return sWork
End_Function

//=============================================================================
/// @Name        MertechInc_Set_DecSep
/// @Description Saves the current decimal separator and sets the decimal separator to '.'
/// @Status      Internal
/// @Drivers     n/a
/// @VersionNote Last Revised: 2009-08-17 By Ian Smith
///
Procedure MertechInc_Set_DecSep Global
    Get_Attribute DF_DECIMAL_SEPARATOR to MertechInc_iDecSep
    If MertechInc_iDecSep Ne 46 Set_Attribute DF_DECIMAL_SEPARATOR to 46 // (.) WILL BE DECIMAL SEPARATOR
End_Procedure

//=============================================================================
/// @Name        MertechInc_Reset_DecSep
/// @Description Sets the decimal separator to the saved value
/// @Status      Internal
/// @Drivers     n/a
/// @VersionNote Last Revised: 2009-08-17 By Ian Smith
///
Procedure MertechInc_Reset_DecSep Global
    If MertechInc_iDecSep Ne 46 Set_Attribute DF_DECIMAL_SEPARATOR to MertechInc_iDecSep
End_Procedure

//=============================================================================
/// @Name        FETCH_FIELD
/// @Description Selects or de-selects the fields to be fetched during the next FIND (query)
/// @Status      Internal Use Only
/// @Drivers     All
/// @VersionNote Last Revised: 2009-07-16 By Ian Smith
///
/// @Syntax FETCH_FIELD <FileNum> <FieldStart> THRU <FieldEnd> TO DF_FETCH_TRUE
/// @Param  FileNum    is the File Number
/// @Param  FieldStart is the Field Name or Number that will start the selection range
/// @Param  FieldEnd   is the Field Name or Number that will finish the selection range
///
/// @Syntax FETCH_FIELD <FileNum> <Field1> TO DF_FETCH_TRUE
/// @Param  FileNum  is the File Number
/// @Param  Field1 Fields Name or Number to be selected
///
#COMMAND FETCH_FIELD
    DO_GETFILENUMBER_DRIVERNAME !1
    If (MertechInc_FileNumber <> -1) Begin
        #IFSAME !3 to   //Single Field
            #IFTYPE !2 "I"  //Number passed
                Move !2 to MertechInc_iArg
            #ELSE   //name passed so workout number
                Move (Length(|CS'!2')) to MertechInc_iArg
                Move (MertechInc_iArg - POS(",",|CS'!2')) to MertechInc_iArg
                Move (Right(|CS'!2',MertechInc_iArg)) to MertechInc_iArg
            #ENDIF
            Move (Uppercase(!4)) to MertechInc_sArg1
            Call_Driver MertechInc_FileNumber MertechInc_DriverName Function 7 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank MertechInc_iArg RESULT MertechInc_iRet
            If MertechInc_iRet EQ -1 Indicate ERR True
        #ELSE
            #IFSAME !3 THRU //multiple fields
                #CHECK !2 RLGU#
                #CHECK !4 RLGU#
                Move (Uppercase(!6)) to MertechInc_sArg1
                If (!2>!4) Error 77
                Else ;
                    For MertechInc_iArg from !2 to !4  //compiler sorts out from to field numbers
                        Call_Driver MertechInc_FileNumber MertechInc_DriverName Function 7 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank MertechInc_iArg RESULT MertechInc_iRet
                        If MertechInc_iRet EQ -1 Indicate ERR True
                    Loop
            #ENDIF
        #ENDIF
    End
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_TEXT_MESSAGE
/// @Description Puts the specified text into the trace file if tracing is turned on.
/// @Assumptions *** The text string is less than 256 characters long. ***
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-14 By Ian Smith
/// @See         ENABLE_TRACE_ON DISABLE_TRACE_ON
///
/// @Syntax SQL_TEXT_MESSAGE <SQL TEXT MESSAGE>
/// @Param SQL TEXT MESSAGE The trace text
///
/// @Example
/// #INCLUDE MERTECH.INC
/// LOGIN "severname" "username" "password" "ora_drv"
///
/// ENABLE_TRACE_ON "c:\trace.txt" DEBUG_LEVEL
/// SQL_TEXT_MESSAGE "BEFORE OPEN"
/// open SALESP
/// SQL_TEXT_MESSAGE "AFTER THE DO OPEN"
/// find GT SALESP by INDEX.1
/// SQL_TEXT_MESSAGE "AFTER FIND"

#COMMAND SQL_TEXT_MESSAGE R .
    MOVE !1 TO MertechInc_sArg1
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        Call_Driver 0 MertechInc_DriverName Function 17 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 0 RESULT MertechInc_iRet
        IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
    End
#ENDCOMMAND

//=============================================================================
/// @Name       SELECT_COLUMNS_FIND
/// @Description
/// Selects specific columns to be fetched by a FIND command.
///
/// SELECT_COLUMNS_FIND will select and fetch only the columns between
/// numbers FieldStart till FieldEnd to be receive a value during a FIND execution.
/// Before calling SELECT_COLUMNS_FIND, make sure you have called
/// RESET_FETCH_FIELDS with DF_FETCH_FALSE first to deselect all fields.
///
/// NOTE:  Recnum and fields that are part of the used index segment will always be fetched.
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-07-16 By Ian Smith
///
/// @Syntax SELECT_COLUMNS_FIND <FileNum|FileName> <FieldStart> THRU <FieldEnd>
/// @Param  FileNum    is the File Number
/// @Param  FileName   is the File Name
/// @Param  FieldStart is the Field Name or Number that will start the selection range
/// @Param  FieldEnd   is the Field Name or Number that will finish the selection range
/// @Usage  SELECT_COLUMNS_FIND CUSTOMER 1 thru 4
///
/// @Syntax SELECT_COLUMNS_FIND <FileNum|FileName> <Field1> {... <Fieldn>}
/// @Param  FileNum  is the File Number
/// @Param  FileName is the File Name
/// @Param  Field1 {... <Fieldn>} List of Fields Name or Number that will be selected
/// @Usage  SELECT_COLUMNS_FIND CUSTOMER CUSTOMER_NUMBER NAME ADDRESS CITY
/// @Usage  SELECT_COLUMNS_FIND CUSTOMER 1 2 3 4
///
/// @See         RESET_FETCH_FIELDS
/// @Example
/// #INCLUDE MERTECH.INC
/// LOGIN "servername" "username" "password" "ora_drv"
/// open CUSTOMER
///
/// // Instruct the driver to only fetch fields 1 through 4
/// RESET_FETCH_FIELDS CUSTOMER DF_FETCH_FALSE
///    SELECT_COLUMNS_FIND CUSTOMER 1 thru 4
///    find gt CUSTOMER by INDEX.1
///    showln CUSTOMER.NUMBER CUSTOMER.NAME CUSTOMER.ADDRESS CUSTOMER.CITY
/// RESET_FETCH_FIELDS CUSTOMER DF_FETCH_TRUE


#COMMAND SELECT_COLUMNS_FIND
    #IFCLASS !1 "V"
        #IFDEF !2
        #ELSE
            CHECK !1 "F"
        #ENDIF
    #ENDIF
    #IFSAME !3 THRU
        #IFDEF !2
            #IFDEF !4
                FETCH_FIELD !1 !2 THRU !4 TO DF_FETCH_TRUE
            #ELSE
                FETCH_FIELD !1 !2 THRU !1.!4 TO DF_FETCH_TRUE
            #ENDIF
        #ELSE
            #IFDEF !4
                FETCH_FIELD !1 !1.!2 THRU !4 TO DF_FETCH_TRUE
            #ELSE
                FETCH_FIELD !1 !1.!2 THRU !1.!4 TO DF_FETCH_TRUE
            #ENDIF
        #ENDIF
    #ELSE
        #IFDEF !2
          #IFCLASS !2 "F"
              FETCH_FIELD !1 !2 TO DF_FETCH_TRUE
          #ELSE
              #CHECK !2 _G#L
              FETCH_FIELD !1 !2 TO DF_FETCH_TRUE
          #ENDIF
        #ELSE
            FETCH_FIELD !1 !1.!2 TO DF_FETCH_TRUE
        #ENDIF
        #IF !0>2
            SELECT_COLUMNS_FIND !1 !3 !4 !5 !6 !7 !8 !9
        #ENDIF
    #ENDIF
#ENDCOMMAND

#REPLACE SET_FETCH_FIELDS SELECT_COLUMNS_FIND

//=============================================================================
/// @Name        RESET_FETCH_FIELDS
/// @Description Instructs the driver to fetch none or all of the columns of a table
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-07-16 By Ian Smith
/// @See         SELECT_COLUMNS_FIND
///
/// @Comment RECNUM and indexed fields will always be fetched
/// @Syntax  RESET_FETCH_FIELDS <FileNum|FileName> DF_FETCH_TRUE|DF_FETCH_FALSE
/// @Param   FileNum        is the File Number
/// @Param   FileName       is the File Name
/// @Param   DF_FETCH_TRUE  fetch all columns
/// @Param   DF_FETCH_FALSE fetch no column
/// @Usage   RESET_FETCH_FIELDS CUSTOMER DF_FETCH_FALSE
/// @Usage   RESET_FETCH_FIELDS CUSTOMER DF_FETCH_TRUE
///
#COMMAND RESET_FETCH_FIELDS R R .
    FETCH_FIELD !1 DF_FETCH_ALL TO !2
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_FOR_ONEROW
/// @Description This command will instruct the driver to fetch one row per query
/// @Status      Deprecated
/// @Drivers     All
/// @VersionNote Last Revised: 2009-07-16 By Ian Smith
///
/// @Syntax SQL_FOR_ONEROW <FileNum|FileName>
/// @Param  FileNum  is the File Number
/// @Param  FileName is the File Name
/// @Usage  SQL_FOR_ONEROW CUSTOMER.FILE_NUMBER
/// @Usage  SQL_FOR_ONEROW 10
///
/// @Example
///     open Salesp
///     SQL_FOR_ONEROW Salesp.File_Number
///     repeat
///         find gt Salesp by Recnum
///         [ found ] begin
///             showln "Sales name is " CUSTOMER.CUSTOMER
///         end
///     until [ finderr ]
///
#COMMAND SQL_FOR_ONEROW R .
    #IFDEF MertechInc_Obsolete_Code
        DO_GETFILENUMBER_DRIVERNAME !1
        If (MertechInc_FileNumber <> -1) Begin
            Call_Driver MertechInc_FileNumber MertechInc_DriverName Function 12 CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 0 RESULT MertechInc_iRet
            If MertechInc_iRet EQ -1 INDICATE ERR True
        End
    #ELSE
        MertechInc_Error_Obsolete_Code
    #ENDIF
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_REFRESH_CACHE
/// @Description
/// Forces the next FIND command to retrieve the record from the database.
///
/// This command allows the user to refresh the current cache forcing the next find
/// command to retrieve the record from the database.
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-07-16 By Ian Smith
///
/// @Syntax SQL_REFRESH_CACHE OF <FileNum|FileName>
/// @Param  FileNum  is the File Number
/// @Param  FileName is the File Name
/// @Usage  SQL_REFRESH_CACHE CUSTOMER.FILE_NUMBER
/// @Usage  SQL_REFRESH_CACHE 10
///
/// @Example
/// #INCLUDE MERTECH.INC
/// Open CUSTOMER
/// repeat
///     find gt CUSTOMER by RECNUM
///     [found] begin
///         showln "Customer name is " CUSTOMER.CUSTOMER
///     end
/// until [finderr]
///
/// // A subsequent find on one of the last couple of records
/// // fetched would normally come from the cache, but the following
/// // call will ensure they are re-fetched from the database
/// SQL_REFRESH_CACHE of CUSTOMER
///

#COMMAND SQL_REFRESH_CACHE OF R .
    DO_GETFILENUMBER_DRIVERNAME !2
    If (MertechInc_FileNumber <> -1) Begin
        Call_Driver MertechInc_FileNumber MertechInc_DriverName Function CALLDRV_SQL_REFRESH_CACHE CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 0 RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_FOR_SET
/// @Description
/// Instructs a SELECT statement to retrieve a set of rows.
///
/// This command will instruct the driver to fetch a set of rows during FIND LT/GT calls.
/// The cache may be disabled by passing NOCACHE
/// The default mode is 10 records and to use cache, and should be
/// adequate for most situations. If the rowcount is set low,
/// performance is impacted due to many round-trips to the server to fetch data.
/// If it is set too high a large number of records can be pre-fetched
/// and end up not being used by the application.
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-10-02 By Ian Smith
///
/// @Syntax SQL_FOR_SET <FileNum|FileName> MAXROWS <MaxNumRows> CACHE|NOCACHE
/// @Param  FileNum     is the File Number
/// @Param  FileName    is the File Name
/// @Param  MaxNumRows  is the maximum number of rows query might have
/// @Param  CACHE       fetched rows will be kept at the local cache
/// @Param  NOCACHE     fetched rows won't be kept at the local cache
/// @Usage  SQL_FOR_SET Customer MAXROWS 15 CACHE
/// @Usage  SQL_FOR_SET Customer MAXROWS 50 NOCACHE
///
/// @Example
/// Open Customer
/// SQL_FOR_SET Customer MAXROWS 15 CACHE
/// find gt Customer by Index.1
///
#COMMAND SQL_FOR_SET R "MAXROWS" R "CACHE""NOCACHE"
    DO_GETFILENUMBER_DRIVERNAME !1
    If (MertechInc_FileNumber <> -1) Begin
        #IFSAME !4 CACHE
            Move "CACHE" to MertechInc_sArg1
        #ELSE
            Move "NOCACHE" to MertechInc_sArg1
        #ENDIF
        Call_Driver MertechInc_FileNumber MertechInc_DriverName Function 13 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank !3 RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND


//=============================================================================
/// @Name        SQL_SET
/// @Description Initializes and set an initial statement for embedded sql execution
/// @Assumptions *** Parameter may be more than 255 characters long so redirect to method. ***
/// @Status      Deprecated
/// @Drivers     All
/// @VersionNote Last Revised: 2009-07-16 By Ian Smith
///
/// @Comment    Use SQL_SET_STMT instead
///
#COMMAND SQL_SET R .
    #IFDEF MertechInc_Obsolete_Code
        DO_GETFILENUMBER_DRIVERNAME 0
        If (MertechInc_FileNumber <> -1) Begin
            INDICATE ERR False
            Send MertechInc_SQL_SET !1
            If MertechInc_iRet EQ -1 INDICATE ERR True
        End
    #ELSE
        MertechInc_Error_Obsolete_Code
    #ENDIF
#ENDCOMMAND

Procedure MertechInc_SQL_SET Global String sStatement
    Call_Driver 0 MertechInc_DriverName Function 1 CALLBACK 0 PASSING MertechInc_Blank sStatement 0 RESULT MertechInc_iRet
End_Procedure

//=============================================================================
/// @Name        SQL_APPEND
/// @Description Appends a string value to the current embedded sql statement already set
/// @Assumptions *** Parameter may be more than 255 characters long so redirect to method. ***
/// @Status      Deprecated
/// @Drivers     All
/// @VersionNote Last Revised: 2009-07-16 By Ian Smith
///
/// @Comment Use SQL_APPEND_STMT instead
///
#COMMAND SQL_APPEND R
    #IFDEF MertechInc_Obsolete_Code
        DO_GETFILENUMBER_DRIVERNAME 0
        If (MertechInc_FileNumber <> -1) Begin
            Send MertechInc_SQL_APPEND !1
            If MertechInc_iRet EQ -1 INDICATE ERR True

            #IF (!0>1)
                SQL_APPEND !2 !3 !4 !5 !6 !7 !8 !9
            #ENDIF
        End
    #ELSE
        MertechInc_Error_Obsolete_Code
    #ENDIF
#ENDCOMMAND

Procedure MertechInc_SQL_APPEND Global String sStatement
    Call_Driver 0 MertechInc_DriverName Function 2 CALLBACK 0 PASSING MertechInc_Blank sStatement 0 RESULT MertechInc_iRet
End_Procedure

//=============================================================================
/// @Name        SQL_EXECUTE
/// @Description Executes the current embedded SQL statement set and commits finishing any pending transaction
/// @Status      Deprecated
/// @Drivers     All
/// @VersionNote Last Revised: 2009-07-16 By Ian Smith
///
/// @Comment Use SQL_EXECUTE_STMT instead
///
#COMMAND SQL_EXECUTE
    #IFDEF MertechInc_Obsolete_Code
        #IF (!0>0)
            SQL_SET !1
            #IF (!0>1)
                SQL_APPEND !2 !3 !4 !5 !6 !7 !8 !9
            #ENDIF
        #ENDIF

        DO_GETFILENUMBER_DRIVERNAME 0
        If (MertechInc_FileNumber <> -1) Begin
            Call_Driver 0 MertechInc_DriverName Function 3 CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 0 RESULT MertechInc_iRet
            If MertechInc_iRet EQ -1 INDICATE ERR True
        End
    #ELSE
        MertechInc_Error_Obsolete_Code
    #ENDIF
#ENDCOMMAND

//=============================================================================
/// @Name        LOCK_TABLE
/// @Description Locks a table. This is equivalent to locking a DAT file.
/// @Status      Deprecated
/// @Drivers     DB2Flex, and ORAFlex 3.x
/// @VersionNote Last Revised: 2009-07-29 By Ian Smith
///
/// @Syntax LOCK_TABLE <FileName>|[<FileName1> <FileName2> <FileName3> ...]
/// @Param  FileName is the file name or the list of file names to be locked
///
#COMMAND LOCK_TABLE R
    #IFDEF MertechInc_Obsolete_Code
        DO_GETFILENUMBER_DRIVERNAME !1
        //DbDKDriver states that function is only vaid for ORAFLEX and not MDSDB2!!!
        If (MertechInc_DriverName EQ ORAFLEX or MertechInc_DriverName EQ MDSDB2) Begin
            Lock
            Call_Driver MertechInc_FileNumber MertechInc_DriverName Function 16 CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 0 RESULT MertechInc_iRet
            If MertechInc_iRet EQ -1 INDICATE ERR True
        End
        #IF !0>1
            LOCK_TABLE !2 !3 !4 !5 !6 !7 !8 !9
        #ENDIF
    #ELSE
        MertechInc_Error_Obsolete_Code
    #ENDIF
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_CHECK_TABLE
/// @Description Verifies if a table exists on the server, If not an error is indicated.
/// @Assumptions *** All three parameters are less than 256 characters long. ***
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-07-29 By Ian Smith
///
/// @Syntax SQL_CHECK_TABLE {DatabaseName} <OwnerName> <TableName>
/// @Param  DatabaseName  Name of the database
/// @Param  OwnerName     Name of the table owner
/// @Param  TableName     Name of the table
///
/// @Usage SQL_CHECK_TABLE "pubs" "dbo" "customer"
/// @Usage SQL_CHECK_TABLE "test" "public" "customer"
/// @Usage SQL_CHECK_TABLE "scott" "customer"
///
/// @Example
/// SQL_CHECK_TABLE "test" "dbo" customer"
/// [FINDERR] BEGIN
///     SHOWLN "Table customer does not exist"
///     ABORT
/// END

#COMMAND SQL_CHECK_TABLE R R
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        Move !1 to MertechInc_sArg1
        #IF (!0>2)
            Append MertechInc_sArg1 "*" !2
            Move !3 to MertechInc_sArg2
        #ELSE
            Move !2 to MertechInc_sArg2
        #ENDIF
        Call_Driver 0 MertechInc_DriverName Function 4 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_sArg2 0 RESULT MertechInc_iRet
        If MertechInc_iRet EQ 0 INDICATE Found False
        Else INDICATE Found True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        SET_SQL_CONSTRAINT
/// @Description This command allows you to put an additional constraint on your
/// finds, moving filtering to the SQL side.
///
/// Using this command can have a significant positive impact on performance,
/// since by moving filtering to the server side network traffic is cut down.
///
/// The constraint can also be used together with programmatic default values
/// to always constrain your finds by the value of another column. Please see
/// the Programmer's Guide for more information.
/// @Assumptions *** Parameter may be more than 255 characters long so redirect to method. ***
/// @Status      Public
/// @Drivers     SQLFlex, ORAFlex, MDSMySQL & MDSPgSQL (not DB2)
/// @VersionNote Last Revised: 2010-10-01 By: Marcelo
///
/// @Syntax SET_SQL_CONSTRAINT OF <FileName|FileNumber> TO <Constraint_Expression>
/// @Param  FileName              Name of the File to receive the Constraint Expression
/// @Param  FileNumber            Number of the File to receive the Constraint Expression
/// @Param  Constraint_Expression A SQL expression that constraints (limits) the data view for a File.
///
/// @Syntax SET_SQL_CONSTRAINT OF <FileName|FileNumber> FROM_PROGRAMMATIC_DEFAULT
/// @Param  FileName              Name of the File to receive the Constraint Expression
///
/// @See    SQL_CONSTRAINT GET_SQL_CONSTRAINT
///
/// @Example
/// // This example will constrain your finds to only find customers in California
/// SET_SQL_CONSTRAINT of customer to ("AND state = 'CA'")
/// SQL_CONSTRAINT     of customer to ACTIVATE
///
/// Repeat
///     Find Gt customer By Index.1
///     Showln customer.name " - " customer.state
/// Until (Not(Found))
///
/// // This example designates field 2 of customer th be the programmatic default.
/// // Any inserts into the customer table where field 2 has not been touched
/// // will receive a value of 'Customer 2', and additionally any FINDs done against
/// // the customer table will only find rows where field number 2 has the value "Customer 2"
/// SET_ATTRIBUTE DF_FIELD_PROGRAMMATIC_DEFAULT of customer.file_number 2 "Customer 2"
/// SET_SQL_CONSTRAINT of customer From_Programmatic_Defaults
/// SQL_CONSTRAINT     of customer to ACTIVATE
///
/// Repeat
///     Find Gt customer By Index.2
///     Showln customer.name " - " customer.state
/// Until (Not(Found))
///
#COMMAND SET_SQL_CONSTRAINT "OF" R "TO""FROM_PROGRAMMATIC_DEFAULTS"
    DO_GETFILENUMBER_DRIVERNAME !2
    If (MertechInc_DriverName EQ SQLFLEX or MertechInc_DriverName EQ ORAFLEX or MertechInc_DriverName EQ MDSMySQL or MertechInc_DriverName EQ MDSPgSQL) Begin
        #IFSAME !3 to
            // We will leave the driver to take care of the constrain expression
            If MertechInc_DriverName EQ SQLFLEX Send MertechInc_SET_SQL_CONSTRAINT 36 !4
            Else                                Send MertechInc_SET_SQL_CONSTRAINT 37 !4
            If MertechInc_iRet EQ -1 INDICATE ERR True
        #ELSE
            If MertechInc_DriverName EQ SQLFLEX Send MertechInc_SET_SQL_CONSTRAINT_PROGRAMMATIC 36
            Else                                Send MertechInc_SET_SQL_CONSTRAINT_PROGRAMMATIC 37
            If MertechInc_iRet EQ -1 INDICATE ERR True
        #ENDIF
    End
#ENDCOMMAND

Procedure MertechInc_SET_SQL_CONSTRAINT Global Integer iFunction String sConstraint
    Call_Driver MertechInc_FileNumber MertechInc_DriverName Function iFunction CALLBACK 0 PASSING sConstraint MertechInc_Blank 0 RESULT MertechInc_iRet
End_Procedure

Procedure MertechInc_SET_SQL_CONSTRAINT_PROGRAMMATIC Global Integer iFunction
    Call_Driver MertechInc_FileNumber MertechInc_DriverName Function iFunction CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 4 RESULT MertechInc_iRet
End_Procedure

//=============================================================================
/// @Name        GET_SQL_CONSTRAINT
/// @Description This command will return the current constraint (if any) on the given file.
/// @Assumptions *** Parameter may be more than 255 characters long so redirect to method. ***
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-11-24 By: Marcelo
/// @See    SQL_CONSTRAINT SET_SQL_CONSTRAINT
///
/// @Syntax GET_SQL_CONSTRAINT OF <FileName|FileNumber> TO <Constraint_Expression>
/// @Param  FileName              Name of the File to receive the Constraint Expression
/// @Param  FileNumber            Number of the File to receive the Constraint Expression
/// @Param  Constraint_Expression A SQL expression that constraints (limits) the data view for a File.
///
#COMMAND GET_SQL_CONSTRAINT "OF" R "TO" R .
    DO_GETFILENUMBER_DRIVERNAME !2
    If (MertechInc_FileNumber <> -1) Begin
        If MertechInc_DriverName EQ SQLFLEX Get MertechInc_GET_SQL_CONSTRAINT 36 TO !4
        Else                                Get MertechInc_GET_SQL_CONSTRAINT 37 TO !4

        IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
    END
#ENDCOMMAND

Function MertechInc_GET_SQL_CONSTRAINT Global Integer iFunction Returns String
    Local String sConstraint
    Get MertechInc_Pre_Size_String 0 to sConstraint

    Call_Driver MertechInc_FileNumber MertechInc_DriverName Function iFunction CALLBACK 0 PASSING sConstraint MertechInc_Blank 3 RESULT MertechInc_iRet
    Function_Return sConstraint
End_Function

//=============================================================================
/// @Name        SQL_CONSTRAINT
/// @Description Activates or Deactivates a previously set SQL constraint on the given file
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-07-29 By Ian Smith
/// @See         SET_SQL_CONSTRAINT GET_SQL_CONSTRAINT
///
/// @Syntax SQL_CONSTRAINT of <FileName> to Activate|Deactivate
/// @Param  FileName   is the name of the file
/// @Param  Activate   Activates the constraint
/// @Param  Deactivate Deactivates the constraint
///
#COMMAND SQL_CONSTRAINT "OF" R TO "ACTIVATE""DEACTIVATE" .
    DO_GETFILENUMBER_DRIVERNAME !2
    If (MertechInc_FileNumber <> -1) Begin
        If MertechInc_DriverName EQ SQLFLEX Move 36 to MertechInc_iFunction
        Else                                Move 37 to MertechInc_iFunction

        #IFSAME !4 ACTIVATE
            Call_Driver MertechInc_FileNumber MertechInc_DriverName Function MertechInc_iFunction CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 1 RESULT MertechInc_iRet
        #ELSE
            Call_Driver MertechInc_FileNumber MertechInc_DriverName Function MertechInc_iFunction CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 2 RESULT MertechInc_iRet
        #ENDIF
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        CREATE_TD_FILE
/// @Description A .TD file is created when the attribure is set to DFTRUE
/// @Status      Deprecated
/// @Drivers     All
/// @VersionNote Last Revised: 2009-07-29 By Ian Smith
///
/// @Syntax CREATE_TD_FILE DFTRUE|DFFALSE
/// @Param
///
#COMMAND CREATE_TD_FILE R
    #IFDEF MertechInc_Obsolete_Code
        DO_GETFILENUMBER_DRIVERNAME 0
        If (MertechInc_FileNumber <> -1) Begin
            Call_Driver 0 MertechInc_DriverName Function 5 CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank !1 RESULT MertechInc_iRet
            If MertechInc_iRet EQ -1 INDICATE ERR True
        End
    #ELSE
        MertechInc_Error_Obsolete_Code
    #ENDIF
#ENDCOMMAND

//=============================================================================
/// @Name        OPEN_INT
/// @Description
/// Opens the .INT files of the table specified when using an OPEN AS command instead
/// opening the DAT file.
///
/// OPEN_INT replaces the DataFlex OPEN command.  The command will check to see
/// if the open command uses an alias name.  If it does then it will try to
/// open an intermediate file, if there is one.
/// Otherwise, it will issue a normal OPEN command.
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-05 By Ian Smith
///
/// @Syntax OPEN_INT <FileName> as <AliasName>
/// @Param  FileName  Contains the file name trying to open.
/// @Param  AliasName Contains the Alias name for the file trying to open.
/// @Example
/// #INCLUDE MERTECH.INC
/// LOGIN "servername" "username" "password" "ora_drv"
/// OPEN_INT "SALESP" as SALESP

#COMMAND OPEN_INT
    #IFSAME !2 as   // CHECK IF THERE IS AN INTERMEDIATE FILE TO OPEN
        Move (UPPERCASE(!1)) to MertechInc_sWork
        Get Seq_New_Channel  to MertechInc_iWork

        If (MertechInc_iWork <> DF_SEQ_CHANNEL_NOT_AVAILABLE) Begin
            If (POS(".INT",MertechInc_sWork) EQ 0) Begin
                Direct_Input channel MertechInc_iWork (!1 + ".INT")
                [ not SeqEof ] Begin // OPEN THE INTERMEDIATE FILE
                    Close_Input channel MertechInc_iWork
                    DO_GETFILENUMBER_DRIVERNAME 0
                    If (MertechInc_FileNumber <> -1) Begin
                        API_OPEN (MertechInc_DriverName + ":" + !1) !2 !3 !4 !5 !6 !7 !8 !9
                    End
                End
                [ SeqEof ] Begin // THERE ISN'T INTERMEDIATE FILE
                    INDICATE ERR False
                    Close_Input channel MertechInc_iWork
                    API_OPEN !1 !2 !3 !4 !5 !6 !7 !8 !9
                End
            End
            Else Begin
                REPLACE ".INT" IN MertechInc_sWork WITH ""
                DO_GETFILENUMBER_DRIVERNAME 0
                If (MertechInc_FileNumber <> -1) Begin
                    API_OPEN (MertechInc_DriverName + ":" + !1) !2 !3 !4 !5 !6 !7 !8 !9
                End
            End

            Send Seq_Release_Channel MertechInc_iWork
        End
        Else Begin
            Error 25000 "No free channels are available to use for the OPEN_INT command."
        End
    #ELSE
        Declare_Datafile !1

        #IFDEF !1
            Move !1 to FILENUMBER
        #ELSE
            #IFDEF !1.RECNUM
                #SET Q$ !1.RECNUM
            #ELSE
                #SET Q$ !1.FILE_NUMBER
            #ENDIF
            !A [] $82 |CI!q FILENUMBER
        #ENDIF

        Get_Attribute DF_FILE_ROOT_NAME of FILENUMBER to MertechInc_sWork
        Move (UPPERCASE(MertechInc_sWork)) to MertechInc_sWork

        If (POS(".INT",MertechInc_sWork) NE 0) Begin
            REPLACE ".INT" IN MertechInc_sWork WITH ""
            DO_GETFILENUMBER_DRIVERNAME 0
            If (MertechInc_FileNumber <> -1) Begin
                API_OPEN (MertechInc_DriverName + ":" + MertechInc_sWork) as !1
            End
        End
        Else Begin
            API_OPEN !1 !2 !3 !4 !5 !6 !7 !8 !9
        End
    #ENDIF
#ENDCOMMAND


//=============================================================================
/// @Name        SET_OPEN_MODE
/// @Description Controls if the Open command will retrieve the table metadata immediatly or
/// if this will be delayed till needed.
/// @Status      Public
/// @Drivers     MySQLFlex, OraFlex, PgFlex, SQLflex
/// @VersionNote Last Revised: 2011-07-13 By Marcelo
///
/// @Syntax SET_OPEN_MODE TO DEFAULT|LAZY_MODE
///
/// @Usage SET_OPEN_MODE TO DEFAULT
/// @Usage SET_OPEN_MODE TO LAZY_MODE
///
/// @Example
///     SET_OPEN_MODE TO LAZY_MODE
///     Open "customer.int" as customer
///
/// @Example
///     SET_OPEN_MODE TO LAZY_MODE
///     // To open a table without using the INT files in the Lazy mode needs we to specify the number of Fields
///     // along with the open table string, like this:
///     // open "<driverName>:<serverName>\<database>*<owner>*<tableName>=<numberFieds>" as table
///     open "sql_drv:\\sqlserver2008\pubs*dbo*customer=14" as customer
///
///     Structure_Start_Dynamic of customer
///         Move Customer.File_Number to iFileNumber
///
///         Set_Attribute DF_FIELD_LENGTH  Of iFileNumber 1  To 6
///         Set_Attribute DF_FIELD_INDEX   Of iFileNumber 1  To 1
///
///         Set_Attribute DF_FIELD_INDEX   Of iFileNumber 2  To 2
///
///         Set_Attribute DF_FIELD_INDEX   Of iFileNumber 12 To 3
///
///         Set_Attribute DF_FIELD_TYPE    Of iFileNumber 13 To DF_TEXT
///         Set_Attribute DF_FIELD_LENGTH  Of iFileNumber 13 To 1024
///
///         // Index.1
///         Set_Attribute DF_INDEX_NUMBER_SEGMENTS    Of iFileNumber 1   To 1
///         Set_Attribute DF_INDEX_SEGMENT_FIELD      Of iFileNumber 1 1 To 1
///         Set_Attribute DF_INDEX_SEGMENT_CASE       Of iFileNumber 1 1 To DF_CASE_IGNORED
///
///         // Index.2
///         Set_Attribute DF_INDEX_NUMBER_SEGMENTS    Of iFileNumber 2   To 2
///         Set_Attribute DF_INDEX_SEGMENT_FIELD      Of iFileNumber 2 1 To 2
///         Set_Attribute DF_INDEX_SEGMENT_CASE       Of iFileNumber 2 1 To DF_CASE_IGNORED
///         Set_Attribute DF_INDEX_SEGMENT_FIELD      Of iFileNumber 2 2 To 1
///
///         // Index.3
///         Set_Attribute DF_INDEX_NUMBER_SEGMENTS    Of iFileNumber 3   To 2
///         Set_Attribute DF_INDEX_SEGMENT_FIELD      Of iFileNumber 3 1 To 12
///         Set_Attribute DF_INDEX_SEGMENT_FIELD      Of iFileNumber 3 2 To 1
///
///     // Refresh the internal file structure
///     Structure_End_Dynamic of customer
///
/// @Example
///     SET_OPEN_MODE TO LAZY_MODE
///     // To open a table without using the INT files in the Lazy mode needs we to specify the number of Fields
///     // along with the open table string, like this:
///     // open "<driverName>:<serverName>\<database>*<owner>*<tableName>=<numberFieds>" as table
///     open "sql_drv:\\sqlserver2008\pubs*dbo*jtl2004=7" as jtl2004
///
///     Structure_Start_Dynamic of jtl2004
///         Move jtl2004.File_Number to iFileNumber
///
///         Set_Attribute DF_FIELD_INDEX                Of iFileNumber 1 To 2
///
///         // Set Partial Overlap field
///         Set_Attribute DF_FIELD_NAME                 Of iFileNumber 2 To "nino_main"
///         Set_Attribute DF_FIELD_TYPE                 Of iFileNumber 2 To DF_OVERLAP
///         Set_Attribute DF_FIELD_OVERLAP_START        Of iFileNumber 2 to 1
///         Set_Attribute DF_FIELD_OVERLAP_OFFSET_START Of iFileNumber 2 to 1
///         Set_Attribute DF_FIELD_OVERLAP_END          Of iFileNumber 2 To 1
///         Set_Attribute DF_FIELD_OVERLAP_OFFSET_END   Of iFileNumber 2 To 8
///         Set_Attribute DF_FIELD_PARTIAL_OVERLAP      Of iFileNumber 2 To DFTRUE
///         Set_Attribute DF_FIELD_INDEX                Of iFileNumber 2 To 2
///
///         // Set Partial Overlap field
///         Set_Attribute DF_FIELD_NAME                 Of iFileNumber 3 To "nino_char"
///         Set_Attribute DF_FIELD_TYPE                 Of iFileNumber 3 To DF_OVERLAP
///         Set_Attribute DF_FIELD_OVERLAP_START        Of iFileNumber 3 to 1
///         Set_Attribute DF_FIELD_OVERLAP_OFFSET_START Of iFileNumber 3 to 9
///         Set_Attribute DF_FIELD_OVERLAP_END          Of iFileNumber 3 To 1
///         Set_Attribute DF_FIELD_OVERLAP_OFFSET_END   Of iFileNumber 3 To 9
///         Set_Attribute DF_FIELD_PARTIAL_OVERLAP      Of iFileNumber 3 To DFTRUE
///         Set_Attribute DF_FIELD_INDEX                Of iFileNumber 3 To 2
///
///         Set_Attribute DF_FIELD_INDEX                Of iFileNumber 4 To 3
///         Set_Attribute DF_FIELD_INDEX                Of iFileNumber 5 To 3
///
///         // Index.1
///         Set_Attribute DF_INDEX_NUMBER_SEGMENTS    Of iFileNumber 1   To 1
///         Set_Attribute DF_INDEX_SEGMENT_FIELD      Of iFileNumber 1 1 To 1
///
///         // Index.2
///         Set_Attribute DF_INDEX_NUMBER_SEGMENTS    Of iFileNumber 2   To 2
///         Set_Attribute DF_INDEX_SEGMENT_FIELD      Of iFileNumber 2 1 To 3
///         Set_Attribute DF_INDEX_SEGMENT_FIELD      Of iFileNumber 2 2 To 2
///
///         // Index.3
///         Set_Attribute DF_INDEX_NUMBER_SEGMENTS    Of iFileNumber 3   To 4
///         Set_Attribute DF_INDEX_SEGMENT_FIELD      Of iFileNumber 3 1 To 4
///         Set_Attribute DF_INDEX_SEGMENT_FIELD      Of iFileNumber 3 2 To 5
///         Set_Attribute DF_INDEX_SEGMENT_FIELD      Of iFileNumber 3 3 To 3
///         Set_Attribute DF_INDEX_SEGMENT_FIELD      Of iFileNumber 3 4 To 2
///
///     // Refresh the internal file structure
///     Structure_End_Dynamic of jtl2004
///
#COMMAND SET_OPEN_MODE "TO" "DEFAULT""LAZY_MODE" .
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        #IFSAME !4 DEFAULT
            MOVE 0 to MertechInc_sArg1
        #ELSE
            MOVE 1 to MertechInc_sArg1
        #ENDIF

        Call_Driver 0 MertechInc_DriverName Function CALLDRV_LICENSE_ENVIRONMENT_SET CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank CALLDRV_USE_LAZY_OPEN_MODE RESULT MertechInc_iRet
        If MertechInc_iRet EQ 0 INDICATE Found False
        Else INDICATE Found True
    End
#ENDCOMMAND


//=============================================================================
/// @Name        SQL_SET_STMT
/// @Description Assigns an SQL statement to the currently selected cursor.
/// @Assumptions *** Parameter may be more than 255 characters long so redirect to method. ***
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-12 By Ian Smith
///
/// @Syntax SQL_SET_STMT [OF <FileNum|FileName>] TO <SQL Statement>
/// @Param FileNum       is the File Number
/// @Param FileName      is the File Name
/// @Param SQL Statement is the initial SQL statement that will be executed
///
/// @Usage SQL_SET_STMT TO "SELECT * from CUSTOMER"
/// @Usage SQL_SET_STMT OF Customer TO "SELECT * from CUSTOMER"
///
/// @See SQL_SET_STMT SQL_APPEND_STMT SQL_PREPARE_STMT SQL_EXECUTE_STMT SQL_CANCEL_QUERY_STMT SQL_FETCH_NEXT_ROW
/// @Example
/// SQL_SET_STMT to "SELECT CUSTOMER_NUMBER, COMMENTS FROM CUSTOMER WHERE RECNUM = 1"
/// SQL_PREPARE_STMT
/// SQL_EXECUTE_STMT
/// SQL_FETCH_NEXT_ROW INTO liValue lsValue
///
#COMMAND SQL_SET_STMT "OF""TO"""
    #IFSAME !1 OF
        #CHECK !3 "TO"
        DO_GETFILENUMBER_DRIVERNAME !2
        If (MertechInc_FileNumber <> -1) Begin
            Send MertechInc_SQL_SET_STMT !4
            IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
        END
        #IF (!0>4)
            SQL_APPEND_STMT !1 !2 !3 !5 !6 !7 !8 !9
        #ENDIF
    #ELSE
        #CHECK !1 "TO"
        DO_GETFILENUMBER_DRIVERNAME 0
        If (MertechInc_FileNumber <> -1) Begin
            Send MertechInc_SQL_SET_STMT !2
            IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
        END
        #IF (!0>2)
            SQL_APPEND_STMT !1 !3 !4 !5 !6 !7 !8 !9
        #ENDIF
    #ENDIF
#ENDCOMMAND

Procedure MertechInc_SQL_SET_STMT Global String sStatment
    Call_Driver MertechInc_FileNumber MertechInc_DriverName Function 22 CALLBACK 0 PASSING MertechInc_Blank sStatment 0 RESULT MertechInc_iRet
End_Procedure

//=============================================================================
/// @Name        SQL_APPEND_STMT
/// @Description Appends a command string to the command buffer initialized by SQL_SET_STMT.
///
/// SQL_APPEND_STMT was added so that long SQL instructions can be broken into smaller strings and
/// appended to a dynamic command buffer, which is then passed to the database server.
/// The SQL_APPEND_STMT will concatenate a string to the command buffer initialized by the
/// SQL_SET_STMT command. SQL_APPEND_STMT can be called as many times as necessary to fill the
/// buffer with all SQL declarations. Subsequently, the SQL_EXECUTE_STMT command executes the
/// completed command.  The FileNo|FileName must be specified if a SELECT statement is being
/// issued and the data needs to be fetched into the record buffer of the file specified by FileNo|FileName.
///
/// @Assumptions *** Parameter may be more than 255 characters long so redirect to method. ***
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-12 By Ian Smith
/// @See SQL_SET_STMT SQL_APPEND_STMT SQL_PREPARE_STMT SQL_EXECUTE_STMT SQL_CANCEL_QUERY_STMT SQL_FETCH_NEXT_ROW
///
/// @Syntax SQL_APPEND_STMT [OF <FileNum|FileName>]  TO <SQL Statement>
/// @Param FileNum       is the File Number
/// @Param FileName      is the File Name
/// @Param SQL Statement the string to be appended
///
/// @Usage SQL_APPEND_STMT TO " Union all SELECT * from CUSTOMER"
/// @Usage SQL_APPEND_STMT OF Customer TO " CUSTOMER.PHONE_NUMBER, CUSTOMER.FAX_NUMBER"
///
/// @See SQL_SET_STMT SQL_APPEND_STMT SQL_PREPARE_STMT SQL_EXECUTE_STMT SQL_CANCEL_QUERY_STMT SQL_FETCH_NEXT_ROW
///
/// @Example
/// Integer liValue1 liValue2
/// String lsValue1 lsValue2
///
/// SQL_SET_STMT to "SELECT CUSTOMER_NUMBER, CUSTOMER.PHONE_NUMBER, "
/// SQL_APPEND_STMT "CUSTOMER.FAX_NUMBER, COMMENTS FROM CUSTOMER WHERE RECNUM = 1"
/// SQL_PREPARE_STMT
/// SQL_EXECUTE_STMT
/// SQL_FETCH_NEXT_ROW INTO liValue1 liValue2 lsValue1 lsValue2
///
#COMMAND SQL_APPEND_STMT "OF""TO"""
    #IFSAME !1 OF
        #CHECK !3 "TO"
        DO_GETFILENUMBER_DRIVERNAME !2
        If (MertechInc_FileNumber <> -1) Begin
            Send MertechInc_SQL_APPEND_STMT !4
            IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
        END
        #IF (!0>4)
            SQL_APPEND_STMT !1 !2 !3 !5 !6 !7 !8 !9
        #ENDIF
    #ELSE
        #CHECK !1 "TO"
        DO_GETFILENUMBER_DRIVERNAME 0
        If (MertechInc_FileNumber <> -1) Begin
            Send MertechInc_SQL_APPEND_STMT !2
            IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
        END
        #IF (!0>2)
            SQL_APPEND_STMT !1 !3 !4 !5 !6 !7 !8 !9
        #ENDIF
    #ENDIF
#ENDCOMMAND

Procedure MertechInc_SQL_APPEND_STMT Global String sStatement
    Call_Driver MertechInc_FileNumber MertechInc_DriverName Function 22 CALLBACK 0 PASSING MertechInc_Blank sStatement 1 RESULT MertechInc_iRet
End_Procedure

//=============================================================================
/// @Name        APPEND_UPDATE_COLUMN
/// @Description Append a given string to the existing SQL statement alread set
/// @Assumptions *** Parameter may be more than 255 characters long so redirect to method. ***
/// @Status      Internal
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-12 By Ian Smith
///
/// @Syntax APPEND_UPDCOL_STMT <Value> for <File.Field1> {<File.Field2> <File.Fieldn>}
/// @Param Value        Value to update fields with.
/// @Param File.Field1  Field to update
/// @Param File.Field2
/// @Param File.Fieldn
///
#COMMAND APPEND_UPDATE_COLUMN R "FOR" R
    Move (LENGTH(|CS'!3')) to MertechInc_iWork                                     //GET FIELDNUMBER
    Move (MertechInc_iWork - POS(",",|CS'!3')) to MertechInc_iWork
    Move (RIGHT(|CS'!3',MertechInc_iWork)) to MertechInc_iWork
    Get_Attribute DF_FIELD_NAME of MertechInc_FileNumber MertechInc_iWork to MertechInc_sWork    //GET COLUMN NAME
    Send MertechInc_APPEND_UPDATE_COLUMN (","*MertechInc_sWork*"="*String(!1))            //WRITE , COLUMN NAME = VALUE

    If MertechInc_iRet EQ -1 INDICATE ERR True

    #IF (!0>3)
        APPEND_UPDATE_COLUMN !1 FOR !4 !5 !6 !7 !8 !9
    #ENDIF
#ENDCOMMAND

Procedure MertechInc_APPEND_UPDATE_COLUMN Global String sStatement
    Call_Driver MertechInc_FileNumber MertechInc_DriverName Function 22 CALLBACK 0 PASSING MertechInc_Blank sStatement 1 RESULT MertechInc_iRet
End_Procedure

//=============================================================================
/// @Name        SQL_APPEND_UPDCOL_STMT
/// @Description Used to optimize the update process of columns being loaded with the same value.
/// @Status      Deprecated
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-12 By Ian Smith
///
/// @Syntax SQL_APPEND_UPDCOL_STMT {Of FileNo|FileName} Value <Value> for <File.Field1> {<File.Field2> <File.Fieldn>}
/// @Param FileNo       Number of the file in the Filelist
/// @Param FileName     Name of the file
/// @Param Value        Value being placed on the File.Fields
/// @Param File.Field1  Row and Column receiving the value.
/// @Param File.Field2
/// @Param File.Fieldn
///
/// @Usage SQL_APPEND_UPDCOL_STMT of EXAMPLE value 0 ;
///        For EXAMPLE.NUM41 EXAMPLE.NUM42 EXAMPLE.NUM43 ;
///            EXAMPLE.NUM51 EXAMPLE.NUM52 EXAMPLE.NUM53
///
/// @Example
///     #INCLUDE MERTECH.INC
///     OPEN EXAMPLE
///
///     SQL_SET_STMT    of EXAMPLE to "UPDATE EXAMPLE SET"
///     SQL_APPEND_STMT of EXAMPLE to " ASC11='x', ASC12='y', ASC13='z'"
///
///     SQL_APPEND_UPDCOL_STMT of EXAMPLE value 0 ;
///         for EXAMPLE.NUM41 EXAMPLE.NUM42 EXAMPLE.NUM43 ;
///             EXAMPLE.NUM51 EXAMPLE.NUM52 EXAMPLE.NUM53
///
///     SQL_APPEND_STMT of EXAMPLE to " WHERE RECNUM=1"
///
///     SQL_PREPARE_STMT of EXAMPLE
///     SQL_EXECUTE_STMT of EXAMPLE
///
#COMMAND SQL_APPEND_UPDCOL_STMT "OF" R "VALUE" R "FOR" R
    DO_GETFILENUMBER_DRIVERNAME !2
    If (MertechInc_FileNumber <> -1) Begin
        APPEND_UPDATE_COLUMN !4 for !6 !7 !8 !9
    End
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_SET_CURSOR_TYPE
/// @Description Specify the SQL cursor type to be used during the next embedded SQL statement execution
/// @Status      Internal
/// @Drivers     SQLFlex
/// @VersionNote Last Revised: 2009-08-12 By Ian Smith
//
/// @Syntax SQL_SET_CURSOR_TYPE TO TYPE_NONE|TYPE_CLIENT|TYPE_SERVER
/// @Param TYPE_NONE   the default cursor type should be used
/// @Param TYPE_CLIENT a client side cursor should be used
/// @Param TYPE_SERVER a server side cursor should be used
///
#COMMAND SQL_SET_CURSOR_TYPE "TO" "TYPE_NONE""TYPE_CLIENT""TYPE_SERVER"""
    If MertechInc_DriverName EQ SQLFLEX Begin
        Move 0 to MertechInc_iArg
        #IFSAME !2 TYPE_CLIENT
            Move CALLDRV_ENUMERATE_CURSOR_TYPE_CLIENT to MertechInc_iArg
        #ELSE
            #IFSAME !2 TYPE_SERVER
                Move CALLDRV_ENUMERATE_CURSOR_TYPE_SERVER to MertechInc_iArg
            #ELSE
                Move CALLDRV_ENUMERATE_CURSOR_TYPE_NONE to MertechInc_iArg
            #ENDIF
        #ENDIF

        Call_Driver 0 MertechInc_DriverName Function CALLDRV_SET_SQL_CURSOR_TYPE CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank MertechInc_iArg RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        CLEAR_INT_CACHE
/// @Description Clears all cached INT info.
/// @Status      Internal
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-12 By Ian Smith
///
/// @Syntax CLEAR_INT_CACHE
///
#COMMAND CLEAR_INT_CACHE
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_CLEAR_INT_CACHE CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 0 RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        CREATE_INVERSE_KEY_FUNCTIONS
/// @Description Create SQL Functions to handle Inverse Key columns
/// @Status      Internal
/// @Drivers     All (v10.1 and above)
/// @VersionNote Last Revised: 2009-09-25 By Ian Smith
///
/// @Syntax CREATE_INVERSE_KEY_FUNCTIONS
///
#COMMAND CREATE_INVERSE_KEY_FUNCTIONS .
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_CREATE_INVK_FUNCTIONS CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 0 RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_PREPARE_STMT
/// @Description Prepares a statement and opens a cursor to be executed by SQL_EXECUTE_STMT.
///
/// This command tells the server to parse the SQL statement and to allocate cursor handles to
/// be subsequently used to fetch the data.  A cursor can be thought of as a pointer to a record set.
///
/// CURSOR_TYPE argument is only supported by SQLFlex
/// By default SQLFLex is using a TYPE_SERVER cursor type to all embedded SQL
/// We should use TYPE_CLIENT only for the statements that are querying only LOB
/// columns (TEXT, NVARCHAR(MAX), VARCHAR(MAX), IMAGE, VARBINARY(MAX), XML and so on)
///
/// If the cursor type is TYPE_SERVER and a LOB type column is selected,
/// MS SQL Server will not be able to get into a transaction, either explicitly
/// or implicitly through a REREAD, LOCK, SAVERECORD, etc.
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-12 By Ian Smith
/// @See SQL_SET_STMT SQL_APPEND_STMT SQL_PREPARE_STMT SQL_EXECUTE_STMT SQL_CANCEL_QUERY_STMT SQL_FETCH_NEXT_ROW
///
/// @Syntax SQL_PREPARE_STMT [ [OF <FileNum|FileName>] [CURSOR_TYPE TYPE_NONE|TYPE_CLIENT|TYPE_SERVER] ]
/// @Param FileNum     is the File Number
/// @Param FileName    is the File Name
/// @Param CURSOR_TYPE is the SQL cursor type to be used
/// @Param TYPE_NONE   the default cursor type should be used. The same as TYPE_SERVER
/// @Param TYPE_CLIENT a client side cursor should be used
/// @Param TYPE_SERVER a server side cursor should be used. This is the default one.
///
/// @Usage SQL_PREPARE_STMT
/// @Usage SQL_PREPARE_STMT OF CUSTOMER
/// @Usage SQL_PREPARE_STMT CURSOR_TYPE TYPE_SERVER
/// @Usage SQL_PREPARE_STMT OF CUSTOMER CURSOR_TYPE TYPE_CLIENT
///
/// @Example
/// Integer liValue
/// String lsValue
///
/// SQL_SET_STMT to "SELECT CUSTOMER_NUMBER, COMMENTS FROM CUSTOMER WHERE RECNUM = 1"
/// SQL_PREPARE_STMT CURSOR_TYPE TYPE_CLIENT
/// SQL_EXECUTE_STMT
/// SQL_FETCH_NEXT_ROW INTO liValue lsValue
///
#COMMAND SQL_PREPARE_STMT "OF""CURSOR_TYPE"""
    #IFSAME !1 of
        DO_GETFILENUMBER_DRIVERNAME !2
        If (MertechInc_FileNumber <> -1) Begin
            #IFSAME !3 CURSOR_TYPE
                SQL_SET_CURSOR_TYPE to !4
            #ENDIF
            Call_Driver MertechInc_FileNumber MertechInc_DriverName Function 22 CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 2 RESULT MertechInc_iRet
            If MertechInc_iRet EQ -1 INDICATE ERR True
        End
    #ELSE
        DO_GETFILENUMBER_DRIVERNAME 0
        If (MertechInc_FileNumber <> -1) Begin
            #IFSAME !1 CURSOR_TYPE
                SQL_SET_CURSOR_TYPE to !2
            #ELSE
                #CHECK !1 .
            #ENDIF
            Call_Driver MertechInc_FileNumber MertechInc_DriverName Function 22 CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 2 RESULT MertechInc_iRet
            If MertechInc_iRet EQ -1 INDICATE ERR True
        End
    #ENDIF
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_BIND_COLUMN
/// @Description Clears all cached INT info.
/// @Status      Internal
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-12 By Ian Smith
///
/// @Comment This should be merged SQL_BINDCOLUMNS_STMT, but has to remain as a
///          sperate command for compatibility.
///
/// @Syntax SQL_BIND_COLUMN FileNumber FieldNumber | DF_BIND_ALL_COLUMNS
///
#COMMAND SQL_BIND_COLUMN R R .
    DO_GETFILENUMBER_DRIVERNAME !1
    If (MertechInc_FileNumber <> -1) Begin
        #IFTYPE !2 "I"
            Move !2 to MertechInc_iWork
        #ELSE
            Move (LENGTH(|CS'!2')) to MertechInc_iWork
            Move (MertechInc_iWork - POS(",",|CS'!2')) to MertechInc_iWork
            Move (RIGHT(|CS'!2',MertechInc_iWork)) to MertechInc_iWork
        #ENDIF
        Move MertechInc_iWork to MertechInc_sArg1
        Call_Driver MertechInc_FileNumber MertechInc_DriverName Function 22 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 3 RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_BINDCOLUMNS_STMT
/// @Description Tells the driver to fetch the returned data into the specified field
/// of the record buffer of a file.
///
/// The SQL_BINDCOLUMNS_STMT command identifies the variables where the retrieved values
/// will be placed. The order of the bounded fields must be the same as the order of the
/// columns in the Select part of the Set SQL-statement. After execution of the
/// SQL_FETCH_NEXT_ROW command (see example), the contents of the columns retrieved from
/// the server are placed into the corresponding fields of the record buffer of the file
/// specified by FileNo or FileName. To fetch the entire record buffer, use DF_BIND_ALL_COLUMNS.
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-12 By Ian Smith
/// @See SQL_SET_STMT SQL_APPEND_STMT SQL_PREPARE_STMT SQL_EXECUTE_STMT SQL_CANCEL_QUERY_STMT SQL_FETCH_NEXT_ROW
///
/// @Syntax SQL_BINDCOLUMNS_STMT {Of FileNo|FileName} to {Field1 {... Fieldn}}| DF_BIND_ALL_COLUMNS
///
/// @Param FileNo              Number of the file in the Filelist
/// @Param FileName            Name of the file
/// @Param Field1              Fields of the files to receive the values
/// @Param Fieldn
/// @Param DF_BIND_ALL_COLUMNS Indicates that all the columns of the file will be associated in the defined order.
///                            This is used when the entire record is to be fetched.
///
/// @Usage SQL_BINDCOLUMNS_STMT OF File TO File.Field
/// @Usage SQL_BINDCOLUMNS_STMT OF File TO DF_BIND_ALL_COLUMNS
///
/// @Example
/// open SALESP
/// SQL_SET_STMT of SALESP to "SELECT COUNT(*) from salesp"
/// SQL_PREPARE_STMT of SALESP
/// SQL_BINDCOLUMNS_STMT of SALESP to RECNUM
/// SQL_EXECUTE_STMT of SALESP
/// SQL_FETCH_NEXT_ROW of SALESP
/// SHOWLN "TOTAL NUMBER OR RECORDS IN SALESP = " SALESP.RECNUM
///
#COMMAND SQL_BINDCOLUMNS_STMT "OF" !R "TO" !R
    #IFDEF !4
        SQL_BIND_COLUMN !2 !4
    #ELSE
        SQL_BIND_COLUMN !2 !2.!4
    #ENDIF
    #IF (!0>4)
        SQL_BINDCOLUMNS_STMT !1 !2 !3 !5 !6 !7 !8 !9
    #ENDIF
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_EXECUTE_STMT
/// @Description Executes a previously defined SQL statement
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-12 By Ian Smith
/// @VersionNote Last Revised: 2009-11-25 By Gandalf Hernandez (default rowcount is 10)
/// @See SQL_SET_STMT SQL_APPEND_STMT SQL_PREPARE_STMT SQL_EXECUTE_STMT SQL_CANCEL_QUERY_STMT SQL_FETCH_NEXT_ROW
///
/// @Syntax SQL_EXECUTE_STMT [ [OF <FileNum|FileName>] [ROWCOUNT <MaxRowsQuery>] ]
/// @Param FileNum      is the File Number
/// @Param FileName     is the File Name
/// @Param MaxRowsQuery is the maximum number of rows query will fetch to the local cache each time
///
/// @Usage SQL_EXECUTE_STMT ROWCOUNT 10
/// @Usage SQL_EXECUTE_STMT OF CUSTOMER ROWCOUNT 10
///
#COMMAND SQL_EXECUTE_STMT "OF""ROWCOUNT"""
    Move 10 to MertechInc_sArg1         // Initialize the Row_Count value

    #IFSAME !1 OF
        DO_GETFILENUMBER_DRIVERNAME !2
        If (MertechInc_FileNumber <> -1) Begin
            #IFSAME !3 ROWCOUNT
                Move !4 to MertechInc_sArg1
            #ENDIF
            Call_Driver MertechInc_FileNumber MertechInc_DriverName Function 22 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 5 RESULT MertechInc_iRet
            If MertechInc_iRet EQ -1 INDICATE ERR True
        End
    #ELSE
        DO_GETFILENUMBER_DRIVERNAME 0
        If (MertechInc_FileNumber <> -1) Begin
            #IFSAME !1 ROWCOUNT
                Move !2 to MertechInc_sArg1
            #ELSE
                #IF (!0>0)
                    SQL_SET_STMT to !1
                    #IF (!0>1)
                        SQL_APPEND_STMT to !2 !3 !4 !5 !6 !7 !8 !9
                    #ENDIF
                #ENDIF
            #ENDIF
            Call_Driver MertechInc_FileNumber MertechInc_DriverName Function 22 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 5 RESULT MertechInc_iRet
            If MertechInc_iRet EQ -1 INDICATE ERR True
        End
    #ENDIF
#ENDCOMMAND

#Replace SQL_PROCEDURE_EXECUTE SQL_EXECUTE_STMT
#Replace MDS_PROCEDURE_EXECUTE SQL_EXECUTE_STMT

//This alias may be redundant. Is was only called from MertechInc_SQL_FUNCTION_EXECUTE
//which has been recoded to directly call SQL_EXECUTE_STMT - I.S. 2009-09-19
Procedure MertechInc_SQL_PROCEDURE_EXECUTE Global
    SQL_EXECUTE_STMT
End_Procedure

//=============================================================================
/// @Name        SQL_START_TRANSACTION_STMT
/// @Description Start an SQL transaction
/// @Status      Public
/// @Drivers     SQLFlex, ORAFlex, MySQLFlex & PGFlex
/// @VersionNote Last Revised: 2009-09-15 By Ian Smith
/// @See         SQL_COMMIT_STMT SQL_ROLLBACK_STMT
/// @Syntax SQL_START_TRANSACTION_STMT
/// @Example
/// SQL_START_TRANSACTION_STMT
/// SQL_SET_STMT to "UPDATE CUSTOMER SET NAME = 'ABC'"
/// SQL_PREPARE_STMT
/// SQL_EXECUTE_STMT
/// SQL_COMMIT_STMT     // Commit the transaction, which flushes the changes to the customer table
///
#COMMAND SQL_START_TRANSACTION_STMT .
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_DriverName EQ ORAFlex) Begin
        Call_Driver MertechInc_FileNumber MertechInc_DriverName Function 22 CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 9 RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
    Else If (MertechInc_DriverName EQ SQLFlex or MertechInc_DriverName EQ MDSMySQL or MertechInc_DriverName EQ MDSPgSQL) Begin
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_SQL_TRANSACTION CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 0 RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_COMMIT_STMT
/// @Description
/// Commits the current transaction, started with SQL_START_TRANSACTION_STMT.
///
/// @Status      Public
/// @Drivers     SQLFlex, ORAFlex, MDSMySQL & MDSPgSQL (not DB2)
/// @VersionNote Last Revised: 2009-09-15 By Ian Smith
/// @See SQL_START_TRANSACTION_STMT SQL_ROLLBACK_STMT
/// @Syntax SQL_COMMIT_STMT
///
#COMMAND SQL_COMMIT_STMT .
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_DriverName EQ ORAFlex) Begin
        Call_Driver MertechInc_FileNumber MertechInc_DriverName Function 22 CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 7 RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
    Else If (MertechInc_DriverName EQ SQLFlex or MertechInc_DriverName EQ MDSPgSQL or MertechInc_DriverName EQ MDSMySQL) Begin
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_SQL_TRANSACTION CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 1 RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_ROLLBACK_STMT
/// @Description Rolls back an SQL transaction, any data changes inside the transaction
/// will not be committed by the server.
///
/// @Status      Public
/// @Drivers     SQLFlex, ORAFlex, MDSMySQL & MDSPgSQL (not DB2)
/// @VersionNote Last Revised: 2009-09-15 By Ian Smith
/// @See
/// @Syntax SQL_ROLLBACK_STMT
/// @Example
/// SQL_START_TRANSACTION_STMT
/// SQL_SET_STMT to "DELETE FROM CUSTOMER WHERE CUSTOMER_ID = 1234"
/// SQL_PREPARE_STMT
/// SQL_EXECUTE_STMT
/// [ERR] Begin SQL_ERROR_MESSAGE errorString
///       Showln errorString
///       SQL_ROLLBACK_STMT
/// End
/// [not ERR] Showln "SQL Statement successful - committing"
/// [not ERR] SQL_COMMIT_STMT
///
#COMMAND SQL_ROLLBACK_STMT .
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_DriverName EQ ORAFlex) Begin
        Call_Driver MertechInc_FileNumber MertechInc_DriverName Function 22 CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 8 RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
    Else If (MertechInc_DriverName EQ SQLFlex or MertechInc_DriverName EQ MDSPgSQL or MertechInc_DriverName EQ MDSMySQL) Begin
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_SQL_TRANSACTION CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 2 RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        SET_TRANSACTIONS_ALLOWED
/// @Description Specifies if transactions are allowed
/// @Status      Internal
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-12 By Ian Smith
///
/// @Syntax SET_TRANSACTIONS_ALLOWED OF <Server> TO TRUE | FALSE
/// @Param Server       Name of the server
/// @Param TRUE | FALSE Enable / Disable transactions
///
#COMMAND SET_TRANSACTIONS_ALLOWED "OF" R "TO" R .
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        MOVE !2 to MertechInc_sArg1
        MOVE !4 to MertechInc_iArg
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_TRANSACTIONS_ALLOWED CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank MertechInc_iArg RESULT MertechInc_iRet
        IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
    End
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_FETCH_NEXT_ROW
/// @Description
/// Fetches the next row in the result set returned by a query or stored procedure.
///
/// The SQL_FETCH_NEXT_ROW fetches the next row generated by a query into the buffer of
/// the associated file or variables. The indicators FOUND and FINDERR are set depending
/// on whether the row was fetched or not.
///
/// SQL_FETCH_NEXT_ROW... INTO will fetch the values corresponding to the select list
/// items into the variables defined after the INTO reserved word.
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-12 By Ian Smith
/// @See SQL_SET_STMT SQL_APPEND_STMT SQL_PREPARE_STMT SQL_EXECUTE_STMT SQL_CANCEL_QUERY_STMT SQL_FETCH_NEXT_ROW
///
/// @Syntax SQL_FETCH_NEXT_ROW {OF <FileNo|FileName>}\{INTO <VAR1> {. <VARn>}}
/// @Param FileNo       Number of the file in the Filelist
/// @Param FileName     Name of the file
/// @Param VAR1...VARn  Variable of program
///
/// @Usage SQL_FETCH_NEXT_ROW OF SALESP
/// @Usage SQL_FETCH_NEXT_ROW INTO REC ID NAME
/// @Example
/// #Include mertech.inc
///
/// // Fetching into variables
/// string ID NAME
/// integer REC
/// SQL_SET_STMT to "SELECT * FROM SALESP ORDER"
/// SQL_APPEND_STMT to " BY NAME DESC"
/// SQL_PREPARE_STMT
/// SQL_EXECUTE_STMT
/// repeat
///     SQL_FETCH_NEXT_ROW INTO REC ID NAME
///    [ found ] begin
///        SHOW REC " "
///        SHOW ID " "
///        SHOWLN NAME
///    end
/// until [ finderr ]
/// SQL_CANCEL_QUERY_STMT
///
/// // Fetching into a record buffer
/// open SALESP
/// SQL_SET_STMT of SALESP to "SELECT * FROM SALESP ORDER"
/// SQL_APPEND_STMT of SALESP to " BY NAME DESC"
/// SQL_PREPARE_STMT of SALESP
/// SQL_BINDCOLUMNS_STMT of SALESP to DF_BIND_ALL_COLUMNS
/// SQL_EXECUTE_STMT of SALESP
/// repeat
///    SQL_FETCH_NEXT_ROW of SALESP
///    [ found ] begin
///        SHOW SALESP.RECNUM " "
///        SHOW SALESP.ID " "
///        SHOWLN SALESP.NAME
///    end
/// until [ finderr ]
/// close SALESP
/// SQL_CANCEL_QUERY_STMT

#COMMAND SQL_FETCH_NEXT_ROW """OF""INTO"
    #IFSAME !1 OF
        DO_GETFILENUMBER_DRIVERNAME !2
        #CHECK !3 .
    #ELSE
        DO_GETFILENUMBER_DRIVERNAME 0
    #ENDIF
    If (MertechInc_FileNumber <> -1) Begin
        Call_Driver MertechInc_FileNumber MertechInc_DriverName Function 22 CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 6 RESULT MertechInc_iRet
        If MertechInc_iRet NE 0 INDICATE Found False
        Else Begin
            INDICATE Found True
            Move 0 to MertechInc_iParamCount
            #IFSAME !1 INTO
                DDO_GET_BIND_PARAMETERS !2 !3 !4 !5 !6 !7 !8 !9
            #ENDIF
        End
    End
#ENDCOMMAND

//=============================================================================
/// @Name        GET_RESULT_SET
/// @Description Fetches the next row in the result set returned by a query or stored procedure.
/// @Status      Deprecated
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-19 By Ian Smith
///
/// @Syntax GET_RESULT_SET INTO <VAR1> {. <VARn>}
/// @Param Var1..Varn   Variables receiving the result set.
///
#COMMAND GET_RESULT_SET "INTO" R
    SQL_FETCH_NEXT_ROW !1 !2 !3 !4 !5 !6 !7 !8 !9
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_GET_DATA_CHUNK
/// @Description Get a chunk of data from a column returned through embedded SQL.
/// @Status      Public
/// @Drivers     SQLFlex
/// @VersionNote Last Revised: 2009-09-15 By Ian Smith
///
/// @Syntax SQL_GET_DATA_CHUNK COLUMN <col> OFFSET <offset> TO <variable> <length>
/// @Param col      column to return data from
/// @Param offset   data is returned starting at offset
/// @Param variable Variable to receive the returned data
/// @Param length   The length of data returned
///
/// @See SQL_GET_DATA_CHUNK SQL_SET_CHUNK_SIZE SQL_GET_CHUNK_SIZE
/// @See SQL_SET_MAX_DATA_SIZE SQL_GET_MAX_DATA_SIZE
///
/// @Example
/// SQL_GET_DATA_CHUNK COLUMN 1 OFFSET liOffset TO lsValue liLen
/// While liLen gt 0
///     Move (liLen + liOffset) to liOffset
///     SQL_GET_DATA_CHUNK COLUMN 1 OFFSET liOffset to lsValue liLen
/// Loop
///
#COMMAND SQL_GET_DATA_CHUNK "COLUMN" R "OFFSET" R "TO" R
    DO_GETFILENUMBER_DRIVERNAME 0

    If (MertechInc_DriverName EQ SQLFLEX) Begin
        Get MertechInc_SQL_GET_DATA_CHUNK !2 !4 to !6
        If MertechInc_iRet EQ -1 INDICATE ERR True
        Else Begin
            #IF (!0 > 6)
                Move MertechInc_sArg1 to !7
            #ENDIF
        End
    End
#ENDCOMMAND

Function MertechInc_SQL_GET_DATA_CHUNK Global Integer iColumn Integer iOffset Returns String
    Local Integer iChuck_Size
    Local String sChunk

    //Get current Chuck size & pre size string
    Call_Driver 0 MertechInc_DriverName Function CALLDRV_CHUNK_SIZE CALLBACK 0 PASSING iChuck_Size MertechInc_Blank 1 RESULT MertechInc_iRet
    Get MertechInc_Pre_Size_String iChuck_Size to sChunk

    //Get data
    Call_Driver 0 MertechInc_DriverName Function CALLDRV_GET_DATA_CHUNK CALLBACK 0 PASSING iColumn sChunk iOffset RESULT MertechInc_iRet

    //sArg1 (iColumn) contains the number of bytes returned, so move it to
    //MertechInc_Arg1 to pass the value back
    Move iColumn to MertechInc_sArg1

    Function_Return sChunk
End_Function

//=============================================================================
/// @Name        SQL_SET_CHUNK_SIZE
/// @Description Set the size of the data chunks returned by SQL_GET_DATA_CHUNK.
/// @Status      Public
/// @Drivers     SQLFlex
/// @VersionNote Last Revised: 2009-08-12 By Ian Smith
///
/// @See SQL_GET_DATA_CHUNK SQL_SET_CHUNK_SIZE SQL_GET_CHUNK_SIZE
/// @See SQL_SET_MAX_DATA_SIZE SQL_GET_MAX_DATA_SIZE
///
/// @Syntax SQL_SET_CHUNK_SIZE TO <Integer>
/// @Param Integer Chuck size
/// @Usage SQL_SET_CHUNK_SIZE TO 16000
///
#COMMAND SQL_SET_CHUNK_SIZE "TO" R
    DO_GETFILENUMBER_DRIVERNAME 0
    IF (MertechInc_DriverName EQ SQLFLEX ) BEGIN
        Get_argument_size to MertechInc_iArg

        //Note this is not good. Setting the Argument size to a large value can impact on performance.
        If (MertechInc_iArg < !2) Set_Argument_Size !2

        Move !2 to MertechInc_sArg1
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_CHUNK_SIZE CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 0 RESULT MertechInc_iRet
        IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
    END
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_GET_CHUNK_SIZE
/// @Description Get the size of the data chunks returned by SQL_GET_DATA_CHUNK.
/// @Status      Public
/// @Drivers     SQLFlex
/// @VersionNote Last Revised: 2009-08-12 By Ian Smith
///
/// @See SQL_GET_DATA_CHUNK SQL_SET_CHUNK_SIZE SQL_GET_CHUNK_SIZE
/// @See SQL_SET_MAX_DATA_SIZE SQL_GET_MAX_DATA_SIZE
///
/// @Syntax SQL_GET_CHUNK_SIZE TO <Integer>
/// @Param Integer Chuck size
///
/// @Usage SQL_GET_CHUNK_SIZE TO iSize
///
#COMMAND SQL_GET_CHUNK_SIZE "TO" R
    DO_GETFILENUMBER_DRIVERNAME 0
    IF (MertechInc_DriverName EQ SQLFLEX ) BEGIN
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_CHUNK_SIZE CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 1 RESULT MertechInc_iRet
        IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
        Else MOVE MertechInc_sArg1 to !2
    END
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_SET_MAX_DATA_SIZE
/// @Description Set the maximum total size of the data returned by SQL_GET_DATA_CHUNK.
/// @Status      Public
/// @Drivers     SQLFlex
/// @VersionNote Last Revised: 2009-08-12 By Ian Smith
///
/// @See SQL_GET_DATA_CHUNK SQL_SET_CHUNK_SIZE SQL_GET_CHUNK_SIZE
/// @See SQL_SET_MAX_DATA_SIZE SQL_GET_MAX_DATA_SIZE
///
/// @Syntax SQL_SET_MAX_DATA_SIZE TO <Integer>
/// @Param Integer Max chuck size
///
/// @Usage SQL_SET_MAX_DATA_SIZE TO 64000
///
#COMMAND SQL_SET_MAX_DATA_SIZE "TO" R
    DO_GETFILENUMBER_DRIVERNAME 0
    IF (MertechInc_DriverName EQ SQLFLEX ) BEGIN
        MOVE !2 TO MertechInc_sArg1
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_MAX_DATA_SIZE CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 0 RESULT MertechInc_iRet
        IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
    END
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_GET_MAX_DATA_SIZE
/// @Description Get the maximum total size of the data returned by SQL_GET_DATA_CHUNK.
/// @Status      Public
/// @Drivers     SQLFlex
/// @VersionNote Last Revised: 2009-08-12 By Ian Smith
///
/// @See SQL_GET_DATA_CHUNK SQL_SET_CHUNK_SIZE SQL_GET_CHUNK_SIZE
/// @See SQL_SET_MAX_DATA_SIZE SQL_GET_MAX_DATA_SIZE
///
/// @Syntax SQL_GET_MAX_DATA_SIZE TO <Integer>
/// @Param Integer Max chuck size
///
/// @Usage SQL_GET_MAX_DATA_SIZE TO iMax_Size
///
#COMMAND SQL_GET_MAX_DATA_SIZE "TO" R
    DO_GETFILENUMBER_DRIVERNAME 0
    IF (MertechInc_DriverName EQ SQLFLEX ) BEGIN
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_MAX_DATA_SIZE CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 1 RESULT MertechInc_iRet
        IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
        Else MOVE MertechInc_sArg1 to !2
    END
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_GET_NUM_COLS
/// @Description Retrieves the number of columns in the result set.
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-12 By Ian Smith
///
/// @Syntax SQL_GET_NUM_COLS [OF <FileNum|FileName>] TO Integer
/// @Param FileNum  is the File Number
/// @Param FileName is the File Name
/// @Param Integer  Number of columns
/// @See   SQL_PREPARE_STMT SQL_EXECUTE_STMT
///
/// @Usage SQL_GET_NUM_COLS OF SALESP TO iCols
/// @Usage SQL_GET_NUM_COLS TO iCols
///
#COMMAND SQL_GET_NUM_COLS "OF""TO"
    #IFSAME !1 OF
        DO_GETFILENUMBER_DRIVERNAME !2
        #CHECK !5 .
    #ELSE
        DO_GETFILENUMBER_DRIVERNAME 0
        #CHECK !3 .
    #ENDIF
    If (MertechInc_FileNumber <> -1) Begin
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_GET_RETURNED_COLUMNS CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 0 RESULT MertechInc_iRet
        #IF !0=2
            Move MertechInc_iRet to !2
        #ELSE
            Move MertechInc_iRet to !4
        #ENDIF
    End
#ENDCOMMAND

#Replace GET_SQL_NUM_COLS SQL_GET_NUM_COLS

//=============================================================================
/// @Name        GET_RESULT_SET_NUM_COLS
/// @Description Returns the number of columns in the result set.
/// @Status      Deprecated
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-19 By Ian Smith
///
/// @Syntax GET_RESULT_SET_NUM_COLS TO <Var>
/// @Param Var      Variable to hold the returned value
///
#COMMAND GET_RESULT_SET_NUM_COLS "TO"
    SQL_GET_NUM_COLS !1 !2
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_GET_NUM_ROWS
/// @Description Retrieves the number of rows in the result set.
///
/// Note: The number of rows may not always be available, depending
/// on server and cursor types.
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-12 By Ian Smith
///
/// @Syntax SQL_GET_NUM_ROWS [OF <FileNum|FileName>] TO Integer
/// @Param FileNum  is the File Number
/// @Param FileName is the File Name
/// @Param Integer  Number of rows
///
/// @See   SQL_PREPARE_STMT SQL_EXECUTE_STMT
///
/// @Usage SQL_GET_NUM_ROWS OF SALESP TO iRows
/// @Usage SQL_GET_NUM_ROWS TO iRows
///
#COMMAND SQL_GET_NUM_ROWS "OF""TO"
    #IFSAME !1 OF
        DO_GETFILENUMBER_DRIVERNAME !2
        #CHECK !5 .
    #ELSE
        DO_GETFILENUMBER_DRIVERNAME 0
        #CHECK !3 .
    #ENDIF
    If (MertechInc_FileNumber <> -1) Begin
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_GET_RETURNED_ROWS CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 0 RESULT MertechInc_iRet
        #IF !0=2
            Move MertechInc_iRet to !2
        #ELSE
            Move MertechInc_iRet to !4
        #ENDIF
    End
#ENDCOMMAND

#Replace GET_SQL_NUM_ROWS SQL_GET_NUM_ROWS

//=============================================================================
/// @Name        SQL_GET_COL_NAME
/// @Description Retrieves the name and size of the specified column
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-12 By Ian Smith
///
/// @Syntax SQL_GET_COL_NAME OF <FileNum|FileName> <viCol> to <vsName> <viSize>
/// @Syntax SQL_GET_COL_NAME <viCol> to <vsName> <viSize>
/// @Param FileNum  is the File Number
/// @Param FileName is the File Name
/// @Param viCol    The column to get attributes for
/// @Param vsName   Variable for column name
/// @Param viSize   Variable for column size
/// @See SQL_GET_NUM_COLS
///
/// @Usage SQL_GET_COL_NAME col to colname size
/// @Usage SQL_GET_COL_NAME OF SalesP col to colname size
///
#COMMAND SQL_GET_COL_NAME
    #IFSAME !1 OF
        DO_GETFILENUMBER_DRIVERNAME !2
        #CHECK !7 .
        MOVE !3 TO MertechInc_iArg
    #ELSE
        #IFSAME !2 TO
            DO_GETFILENUMBER_DRIVERNAME 0
            #CHECK !5 .
            MOVE !1 TO MertechInc_iArg
        #ELSE
            #ERROR 4514
        #ENDIF
    #ENDIF

    If (MertechInc_FileNumber <> -1) Begin
        Move (Repeat(" ", 255)) to MertechInc_sArg1

        Call_Driver 0 MertechInc_DriverName Function CALLDRV_GET_COLUMN_ATTRIBUTE CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank MertechInc_iArg RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
        Else Begin
            #IFSAME !1 of
                Move MertechInc_sArg1 to !5
                #IF !0=6
                    Move MertechInc_iRet to !6
                #ENDIF
            #ELSE
                Move MertechInc_sArg1 to !3
                #IF !0=4
                    Move MertechInc_iRet to !4
                #ENDIF
            #ENDIF
        End
    End
#ENDCOMMAND

#Replace GET_SQL_COL_NAME SQL_GET_COL_NAME

//=============================================================================
/// @Name        GET_RESULT_SET_COL_NAME
/// @Description Returns the column name being populated from the result set.
/// @Status      Deprecated
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-19 By Ian Smith
///
/// @Syntax GET_RESULT_SET_COL_NAME <COL NUMBER> TO <NAME> {<SIZE>}
/// @Param Col Number   Column number to get attributes of
/// @Param Name         Variable for column name
/// @Param Size         Variable for column size
///
#COMMAND GET_RESULT_SET_COL_NAME R "TO"
    SQL_GET_COL_NAME !1 !2 !3 !4
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_GET_COL_ATTRIBUTE
/// @Description Retrieve information about a given column return through embedded SQL
///
/// Supported attributes are:
/// <dl>
/// <dt>SIZE        </dt><dd>Maximum length of column</dd>
/// <dt>DATA_LENGTH </dt><dd>Length of data in column</dd>
/// <dt>DECIMALS    </dt><dd>Number of decimals in the column (if numeric type)</dd>
/// <dt>LABEL       </dt><dd>not used, returns blank</dd>
/// <dt>COLUMN_NAME </dt><dd>Name of column</dd>
/// <dt>TABLE_NAME  </dt><dd>Name of table (may not always be available)</dd>
/// <dt>SQLTYPE     </dt><dd>Underlying SQL type</dd>
/// <dt>NULLABLE    </dt><dd>DFTRUE if columns is nullable</dd>
/// <dt>DFTYPE      </dt><dd>Dataflex type column is mapped to</dd>
/// </dl>
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-12 By Ian Smith
///
/// @Syntax SQL_GET_COL_ATTRIBUTE OF <Col_num> <Attr> TO <Var>
/// @Param Col_num  is the column number
/// @Param Attr     is the attribute to get
/// @Param Var      variable to hold the attribute value.
///
/// @Usage SQL_GET_COL_ATTRIBUTE OF 1 SIZE TO sValue
///
#COMMAND SQL_GET_COL_ATTRIBUTE "OF" R "SIZE""DATA_LENGTH""DECIMALS""LABEL""COLUMN_NAME""TABLE_NAME""SQLTYPE""NULLABLE""DFTYPE" "TO" R
    DO_GETFILENUMBER_DRIVERNAME 0

    If (MertechInc_FileNumber <> -1) Begin
        #IFSAME !3 SIZE
            Move SQL_GET_COL_ATTRIB_SIZE to MertechInc_sArg2
        #ELSE
            #IFSAME !3 DATA_LENGTH
                Move SQL_GET_COL_ATTRIB_DATA_LENGTH to MertechInc_sArg2
            #ELSE
               #IFSAME !3 DECIMALS
                    Move SQL_GET_COL_ATTRIB_DECIMALS to MertechInc_sArg2
                #ELSE
                    #IFSAME !3 LABEL
                        Move SQL_GET_COL_ATTRIB_LABEL to MertechInc_sArg2
                    #ELSE
                        #IFSAME !3 COLUMN_NAME
                            Move SQL_GET_COL_ATTRIB_COLUMN_NAME to MertechInc_sArg2
                        #ELSE
                            #IFSAME !3 TABLE_NAME
                                Move SQL_GET_COL_ATTRIB_TABLE_NAME to MertechInc_sArg2
                            #ELSE
                                #IFSAME !3 SQLTYPE
                                    Move SQL_GET_COL_ATTRIB_SQLTYPE to MertechInc_sArg2
                                #ELSE
                                    #IFSAME !3 NULLABLE
                                        MOVE SQL_GET_COL_ATTRIB_NULLABLE TO MertechInc_sArg2
                                    #ELSE
                                        MOVE SQL_GET_COL_ATTRIB_DFTYPE TO MertechInc_sArg2
                                    #ENDIF
                                #ENDIF
                            #ENDIF
                        #ENDIF
                    #ENDIF
                #ENDIF
            #ENDIF
        #ENDIF

        Move !2 to MertechInc_iArg
        Move (Repeat(" ", 255)) to MertechInc_sArg1
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_GET_COLUMN_ATTRIBUTE CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_sArg2 MertechInc_iArg RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
        Else Move MertechInc_sArg1 to !5
    End
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_NEXT_RESULT_SET
/// @Description Move to the nest result set, when multiple result sets
/// are returned.
/// @Status      Public
/// @Drivers     MySQLFlex
/// @VersionNote Last Revised: 2009-08-12 By Ian Smith
///
/// @Syntax SQL_NEXT_RESULT_SET
/// @Syntax SQL_NEXT_RESULT_SET OF <FileNum|FileName>
/// @Param FileNum      is the File Number
/// @Param FileName     is the File Name
///
#COMMAND SQL_NEXT_RESULT_SET """OF"
    #IFSAME !1 OF
        DO_GETFILENUMBER_DRIVERNAME !2
        #CHECK !3 .
    #ELSE
        DO_GETFILENUMBER_DRIVERNAME 0
    #ENDIF
    IF (MertechInc_DriverName EQ MYSQLFLEX Or MertechInc_DriverName EQ SQLFlex) BEGIN
        Call_Driver MertechInc_FileNumber MertechInc_DriverName Function 22 CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 8 RESULT MertechInc_iRet
        If MertechInc_iRet NE 0 INDICATE Found False
        Else INDICATE Found True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        DDO_PASS_ARGUMENTS
/// @Description Calls DO_PASS_ARGUMENTS until argument is BINDING and then stops
/// @Status      Internal
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-12 By Ian Smith
///
#COMMAND DDO_PASS_ARGUMENTS
    DO_PASS_ARGUMENTS !1
    #IF !0>1
        #IFSAME !1 BINDING
        #ELSE
            DDO_PASS_ARGUMENTS !2 !3 !4 !5 !6 !7 !8 !9
        #ENDIF
    #ENDIF
#ENDCOMMAND

//=============================================================================
/// @Name        DO_PASS_ARGUMENTS
/// @Description Builds parameter statements for store procedures and adds them to the current query.
/// @Status      internal
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-12 By Ian Smith
///
#COMMAND DO_PASS_ARGUMENTS
    #IFSAME !1 BINDING  // DON'T DO ANYTHING ELSE
    #ELSE
        #IFSAME !1 SQLOUT
        #ELSE
          #IFSAME !1 PASSING
              IF (MertechInc_iParamCount = 0 AND MertechInc_DriverName = SQLFLEX OR MertechInc_DriverName = MDSDB2 OR MertechInc_DriverName = MYSQLFLEX) MOVE "(" TO MertechInc_sArg1
          #ELSE
              IF (MertechInc_iParamCount > 0) SQL_APPEND_STMT TO ", "
              INCREMENT MertechInc_iParamCount

              IF (MertechInc_DriverName EQ PGFLEX) MOVE ("$"+string(MertechInc_iParamCount)) TO MertechInc_sArg1
              ELSE IF (MertechInc_DriverName = MYSQLFLEX ) MOVE ("@"+STRING(MertechInc_iParamCount)) TO MertechInc_sArg1
                    ELSE IF MertechInc_DriverName EQ ORAFLEX MOVE (":PAR"+STRING(MertechInc_iParamCount)) TO MertechInc_sArg1
                         ELSE MOVE "? " TO MertechInc_sArg1
          #ENDIF
              SQL_APPEND_STMT TO MertechInc_sArg1
        #ENDIF
        #IF (!0 > 1)
            DO_PASS_ARGUMENTS !2 !3 !4 !5 !6 !7 !8 !9
        #ENDIF
    #ENDIF
#ENDCOMMAND

//=============================================================================
/// @Name        DDO_BIND_PARAMETERS
/// @Description Recursively calls DO_BIND_PARAMETERS until key word BINDING encountered
/// @Status      internal
/// @Drivers     All
/// @VersionNote Last Revised: 2009-09-15 By Ian Smith
///
#COMMAND DDO_BIND_PARAMETERS
//    DO_BIND_PARAMETERS !1
    #IFSAME !1 BINDING
        DO_BIND_PARAMETERS !1
    #ELSE
        #IFSAME !1 PASSING
            DO_BIND_PARAMETERS !1
        #ELSE
            #IFSAME !1 SQLOUT
                DO_BIND_PARAMETERS !1
            #ELSE
                DO_BIND_PARAMETERS (!1)
            #ENDIF
        #ENDIF
    #ENDIF

    #IF !0>1
        #IFSAME !1 BINDING
            // DON'T DO ANYTHING ELSE
        #ELSE
            DDO_BIND_PARAMETERS !2 !3 !4 !5 !6 !7 !8 !9
        #ENDIF
    #ENDIF
#ENDCOMMAND

//=============================================================================
/// @Name        DO_BIND_PARAMETERS
/// @Description Binds parameters for stored procedure call
/// @Status      Internal
/// @Drivers     All
/// @VersionNote Last Revised: 2009-09-18 By Ian Smith
///
/// @Syntax ?? ?? ??
///
#COMMAND DO_BIND_PARAMETERS
    //MertechInc_iWork         - Integer - Size of return buffer
    //MertechInc_sWork         - String  - Default value
    //MertechInc_iParamCount   - Integer - Allocates sequential number for parameter.
    //                              This will have been set to zero somewhere else.

    #IFSAME !1 BINDING
        // DON'T DO ANYTHING ELSE
    #ELSE
        #IFSAME !1 PASSING
        #ELSE
            #IFSAME !1 SQLOUT
            #ELSE
                #IFCLASS !1 _C
                    MOVE !1 TO MertechInc_sArg1
                    Move (LENGTH(MertechInc_sArg1)+1) to MertechInc_iWork

                    #IFTYPE !1 "I"
                        MOVE 20 TO MertechInc_iWork
                    #ELSE
                        #IFTYPE !1 "N"
                            MOVE 50 TO MertechInc_iWork
                        #ELSE
                            #IFTYPE !1 "D"
                                MOVE 20 TO MertechInc_iWork
                            #ELSE
                                #IFTYPE !1 "S"
                                    IF (POS("|VS",|CS'!1') NE 0 OR POS("|WS",|CS'!1') NE 0) MOVE 255 TO MertechInc_iWork
                                    ELSE MOVE 16384 TO MertechInc_iWork
                                #ENDIF
                            #ENDIF
                        #ENDIF
                    #ENDIF

                    // MARCELO 12/14/2006
                    // We will change the default value here due a stored procedure call in ORAFlex
                    // MOVE " " TO MertechInc_sWork
                    MOVE "" TO MertechInc_sWork
                #ELSE
                    #IFTYPE !1 "I"
                        MOVE 20 TO MertechInc_iWork
                        MOVE 0 TO MertechInc_sWork
                    #ELSE
                        #IFTYPE !1 "N"
                            MOVE 50 TO MertechInc_iWork
                            MOVE 0 TO MertechInc_sWork
                        #ELSE
                            #IFTYPE !1 "D"
                                MOVE 20 TO MertechInc_iWork
                                MOVE "" TO MertechInc_sWork
                            #ELSE
                                #IFTYPE !1 "S"
                                    IF (POS("|VS",|CS'!1') NE 0 OR POS("|WS",|CS'!1') NE 0) MOVE 255 TO MertechInc_iWork
                                    ELSE MOVE 16384 TO MertechInc_iWork
                                    MOVE "" TO MertechInc_sWork
                                #ENDIF
                            #ENDIF
                        #ENDIF
                    #ENDIF
                #ENDIF

                INCREMENT MertechInc_iParamCount
                IF MertechInc_DriverName EQ ORAFLEX MOVE (":PAR"+STRING(MertechInc_iParamCount)) TO MertechInc_sArg2
                ELSE IF MertechInc_DriverName EQ MYSQLFLEX MOVE ("@"+STRING(MertechInc_iParamCount)) TO MertechInc_sArg2
                     ELSE MOVE " " TO MertechInc_sArg2

                If (LENGTH(!1) = 0) Begin
                    Send MertechInc_DO_BIND_PARAMETERS MertechInc_sWork MertechInc_sArg2 MertechInc_iWork
                End
                Else Begin
                    Send MertechInc_Set_DecSep     //Check Decimal Seperator and change to '.' if required
                    Send MertechInc_DO_BIND_PARAMETERS !1 MertechInc_sArg2 MertechInc_iWork
                    Send MertechInc_Reset_DecSep   //Reset Decimal Seperator if required
                End
            #ENDIF
        #ENDIF
        #IF (!0>1)
            DO_BIND_PARAMETERS !2 !3 !4 !5 !6 !7 !8 !9
        #ENDIF
    #ENDIF
#ENDCOMMAND

Procedure MertechInc_DO_BIND_PARAMETERS Global String sValue String sName Integer iLength
    Call_Driver 0 MertechInc_DriverName Function 23 CALLBACK 0 PASSING sValue sName iLength RESULT MertechInc_iRet
End_Procedure

//=============================================================================
/// @Name        DO_BIND_PAR_RET
/// @Description Binds parameters for stored procedure call
/// @Status      Internal
/// @Drivers     OraFlex
/// @VersionNote Last Revised: 2009-09-18 By Ian Smith
///
/// @Syntax ?? ?? ??
///
#COMMAND DO_BIND_PAR_RET
    //MertechInc_iWork - Integer - Size of return buffer
    //MertechInc_sWork - String  - Default value

    Move !1 to MertechInc_sArg1

    #IFCLASS !1 _C
        Move (LENGTH(MertechInc_sArg1)+1) to MertechInc_iWork
        Move " " to MertechInc_sWork
    #ELSE
        #IFTYPE !1 "I"
            Move 10 to MertechInc_iWork
            Move 0 to MertechInc_sWork
        #ELSE
            #IFTYPE !1 "N"
                Move 25 to MertechInc_iWork
                Move 0 to MertechInc_sWork
            #ELSE
                #IFTYPE !1 "D"
                    Move 11 to MertechInc_iWork
                    Move "" to MertechInc_sWork
                #ELSE
                    #IFTYPE !1 "S"
                        If (POS("|VS",|CS'!1') NE 0 or POS("|WS",|CS'!1') NE 0) Move 255 to MertechInc_iWork
                        Else Move 16384 to MertechInc_iWork
                        Move "" to MertechInc_sWork
                    #ENDIF
                #ENDIF
            #ENDIF
        #ENDIF
    #ENDIF

    Move (":PAR_RET") to MertechInc_sArg2
    If (LENGTH(MertechInc_sArg1) = 0) Move MertechInc_sWork to MertechInc_sArg1

    Call_Driver 0 MertechInc_DriverName Function 23 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_sArg2 MertechInc_iWork RESULT MertechInc_iRet
#ENDCOMMAND

//=============================================================================
/// @Name        DDO_GET_BIND_PARAMETERS
/// @Description Recursively calls DO_GET_BIND_PARAMETERS
/// @Status      internal
/// @Drivers     All
/// @VersionNote Last Revised: 2009-09-18 By Ian Smith
///
#COMMAND DDO_GET_BIND_PARAMETERS
    DO_GET_BIND_PARAMETERS !1
    #IF !0>1
        DDO_GET_BIND_PARAMETERS !2 !3 !4 !5 !6 !7 !8 !9
    #ENDIF
#ENDCOMMAND

//=============================================================================
/// @Name        DO_GET_BIND_PARAMETERS
/// @Description Gets bound parameters values for stored procedure call
/// @Status      Internal
/// @Drivers     All
/// @VersionNote Last Revised: 2009-09-24 By Ian Smith
///
/// @Syntax ?? ?? ??
///
#COMMAND DO_GET_BIND_PARAMETERS
    #IFSAME !1 BINDING
        // Stop - do not process any more arugments
    #ELSE
        #IFSAME !1 SQLOUT
            // Do nothing, just recurse if more arugments
        #ELSE
            Increment MertechInc_iParamCount
            #IFCLASS !1 _CE
                // Just need to increment the parameter count (done above)
            #ELSE
                DO_GETFILENUMBER_DRIVERNAME 0
                Send MertechInc_Set_DecSep     //Check Decimal Seperator and change to '.' if required
                If (MertechInc_DriverName EQ SQLFLEX) Begin
                    Get MertechInc_DO_GET_BIND_PARAMETERS True MertechInc_iParamCount MertechInc_Blank 7 to !1
                End
                Else Begin
                    Get MertechInc_DO_GET_BIND_PARAMETERS False MertechInc_Blank MertechInc_Blank MertechInc_iParamCount to !1
                End
                Send MertechInc_Reset_DecSep   //Reset Decimal Seperator if required

                If MertechInc_iRet EQ -1 INDICATE ERR True    // Set the error indicator if anything went wrong
            #ENDIF
        #ENDIF
        #IF (!0>1)
            DO_GET_BIND_PARAMETERS !2 !3 !4 !5 !6 !7 !8 !9
        #ENDIF
    #ENDIF
#ENDCOMMAND

Function MertechInc_DO_GET_BIND_PARAMETERS Global Integer bSQLFlex String sArg1 String sArg2 Integer iArg Returns String
    Local String sReturnValue
    Local Integer iSize

    If (bSQLFlex) Begin
        //Ignore sArg2, and allocate a bit extra for NULL
    	SQL_GET_COL_ATTRIBUTE of sArg1 DATA_LENGTH to iSize
        Get MertechInc_Pre_Size_String (iSize+1) to sReturnValue
        Call_Driver 0 MertechInc_DriverName Function 22 CALLBACK 0 PASSING sArg1 sReturnValue iArg RESULT MertechInc_iRet
    End
    Else Begin
        //Ignore sArg1 & sArg2 and allocate a bit extra for NULL
    	SQL_GET_COL_ATTRIBUTE of iArg DATA_LENGTH to iSize
        Get MertechInc_Pre_Size_String (iSize+1) to sReturnValue
        Call_Driver 0 MertechInc_DriverName Function 24 CALLBACK 0 PASSING sReturnValue MertechInc_Blank iArg RESULT MertechInc_iRet
    End

    Function_Return sReturnValue
End_Function

//=============================================================================
/// @Name        SQL_GET_OUTPUT_VALUE
/// @Description Retrieves the value of a stored procedure parameter
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-19 By Ian Smith
///
/// @Syntax SQL_GET_OUTPUT_VALUE <Position> TO <Variable>
/// @Param Position   Parameter to retrieve value of
/// @Param Variable   Variable to hold returned value
///
#COMMAND SQL_GET_OUTPUT_VALUE R "TO" R
    //MertechInc_iSaveCount is used to hold the number of columns in the query and then
    //to save the current parametert count.

  SQL_GET_NUM_COLS to MertechInc_iSaveCount
  If (!1 <= MertechInc_iSaveCount) Begin
      Move MertechInc_iParamCount to MertechInc_iSaveCount
      MOVE (!1 -1) TO MertechInc_iParamCount
      DO_GET_BIND_PARAMETERS !3
      Move MertechInc_iSaveCount to MertechInc_iParamCount
  END
  ELSE BEGIN
      Error 4099    // Bad Parameter
  END
#ENDCOMMAND

#Replace MDS_GET_OUTPUT_VALUE SQL_GET_OUTPUT_VALUE

//=============================================================================
/// @Name        SQL_FETCH_COLUMN
/// @Description Retrieves the specified column from the result set returned by a query or stored procedure.
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-09-25 By Ian Smith
///
/// @Syntax SQL_FETCH_COLUMN <Column> INTO <Var>
/// @Param Columnn    the column to fetch
/// @Param Var        Varible to hold returned value
///
/// @See SQL_FETCH_NEXT_ROW
///
/// @Example
/// // Note: It is more common to use SQL_FETCH_NEXT_ROW INT <vars>
/// // to access column data
///
/// sql_set_stmt to "select id, name from SALESP"
/// sql_prepare_stmt
/// sql_execute_stmt
///
/// SQL_GET_NUM_COLS TO iNumCols
/// For FIELDINDEX From 1 TO iNumCols
///     SQL_GET_COL_NAME FIELDINDEX TO colname PAGEEND
///     SHOW (PAD((colname+"("*STRING(PAGEEND)*")"), 30))
/// Loop
///
/// showln
///
/// For FIELDINDEX From 1 TO iNumRows
///    SQL_FETCH_NEXT_ROW
///    [found] Begin
///        For Windowindex From 1 to iNumCols
///           show " "
///           SQL_FETCH_COLUMN Windowindex INTO column
///           show (PAD(column, 30))
///        Loop
///     showln
///    End
/// Loop

#COMMAND SQL_FETCH_COLUMN R "INTO" R
    DO_GETFILENUMBER_DRIVERNAME 0

    Send MertechInc_Set_DecSep     //Check Decimal Seperator and change to '.' if required
    If (MertechInc_DriverName EQ ORAFLEX or MertechInc_DriverName EQ MDSDB2) Begin
        Get MertechInc_SQL_FETCH_COLUMN True MertechInc_Blank MertechInc_Blank !1 to !3
    End
    Else Begin
        Get MertechInc_SQL_FETCH_COLUMN False !1  MertechInc_Blank 7 to !3
    End
    Send MertechInc_Reset_DecSep   //Reset Decimal Seperator if required
#ENDCOMMAND

Function MertechInc_SQL_FETCH_COLUMN Global Integer bDriver String sArg1 String sArg2 Integer iArg Returns String
    Local String sReturnValue

    Get MertechInc_Pre_Size_String 0 to sReturnValue

    If (bDriver) Begin  //Group one - OraFlex & mdsDB2
        //Ignore sArg1 & sArg2
        Call_Driver 0 MertechInc_DriverName Function 24 CALLBACK 0 PASSING sReturnValue MertechInc_Blank iArg RESULT MertechInc_iRet
    End
    Else Begin          //Group two - All others
        //Ignore sArg2
        Call_Driver 0 MertechInc_DriverName Function 22 CALLBACK 0 PASSING sArg1 sReturnValue iArg RESULT MertechInc_iRet
    End

    Function_Return sReturnValue
End_Function

//=============================================================================
/// @Name        CALL_ORACLE_STORED_PROCEDURE
/// @Description
/// Calls a stored procedure in the Oracle database.
///
/// CALL_ORACLE_STORED_PROCEDURE calls a stored procedure in the Oracle database.
/// With this command it is also possible to pass arguments to this procedure.
/// The return value is stored in VAR_RET. The indicator ERR will be set
/// to a nonzero value if an error occurs.
///
/// @Status      Public
/// @Drivers     ORAFLex
/// @VersionNote Last Revised: 2009-08-18 By Ian Smith
///
/// @Syntax CALL_ORACLE_STORED_PROCEDURE <ProcName> {PASSING <Arg1> {. <Argn>}}
/// @Param ProcName   Full name of the procedure.
/// @Param Arg1.Argn  Arguments passed to the procedure.
/// @Example
/// SQL_SET_STMT    TO 'CREATE OR REPLACE PACKAGE EMP_PKG AS PROCEDURE '
/// SQL_APPEND_STMT TO '  SET_EMPSAL ( SalIN in integer, RowC out integer);  '
/// SQL_APPEND_STMT TO 'END EMP_PKG; '
/// SQL_PREPARE_STMT
/// SQL_EXECUTE_STMT
/// SQL_SET_STMT    TO 'CREATE OR REPLACE PACKAGE BODY EMP_PKG AS '
/// SQL_APPEND_STMT TO '  PROCEDURE SET_EMPSAL ( SalIN in integer, RowC out integer) IS '
/// SQL_APPEND_STMT TO '  BEGIN '
/// SQL_APPEND_STMT TO '     UPDATE EMP SET EMP.SAL = SalIN; '
/// SQL_APPEND_STMT TO '     RowC := SQL%ROWCOUNT; '
/// SQL_APPEND_STMT TO '  END SET_EMPSAL; '
/// SQL_APPEND_STMT TO 'END EMP_PKG; '
/// SQL_PREPARE_STMT
/// SQL_EXECUTE_STMT
///
/// INTEGER SAL RET
/// STRING ERRORSTRING
/// move 300 to SAL
///
/// SQL_START_TRANSACTION_STMT
///   CALL_ORACLE_STORED_PROCEDURE 'emp_pkg.set_empsal' passing SAL ret
///   [ ERR ] begin
///     SQL_ERROR_MESSAGE errorString
///     SHOWLN errorString
///     SQL_ROLLBACK_STMT
///     ABORT
///   end
///
/// SQL_COMMIT_STMT
///
/// showln 'PROCEDURE EXECUTED'
/// showln 'Total Lines Modified equals ' RET
/// showln 'All salaries were modified to ' SAL

#COMMAND CALL_ORACLE_STORED_PROCEDURE R "PASSING"""
    MOVE 0 TO MertechInc_iParamCount
    INDICATE ERR FALSE
    SQL_SET_STMT TO "BEGIN "
    SQL_APPEND_STMT TO !1 "( "
    #IF (!0>2)
        DDO_PASS_ARGUMENTS !3 !4 !5 !6 !7 !8 !9
    #ENDIF
    SQL_APPEND_STMT TO  " ); END;"
    SQL_PREPARE_STMT
    #IF (!0>2)
        [ NOT ERR ] BEGIN
            IF MertechInc_iParamCount GT 0 BEGIN
                MOVE 0 TO MertechInc_iParamCount
                DDO_BIND_PARAMETERS !3 !4 !5 !6 !7 !8 !9
            END
        END
    #ENDIF
    SQL_EXECUTE_STMT
    [ NOT ERR ] BEGIN
        If ( MertechInc_iParamCount GT 0 ) BEGIN
            MOVE 0 TO MertechInc_iParamCount
            DDO_GET_BIND_PARAMETERS !3 !4 !5 !6 !7 !8 !9
        END
    END
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_SET_PROCEDURE_NAME
/// @Description Sets the name of a stored procedure to execute
/// @Status      Public
/// @Drivers     ORAFLex, MsSQLFlex
/// @VersionNote Last Revised: 2009-09-19 By Ian Smith
///
/// @Syntax SQL_SET_PROCEDURE_NAME <ProcName> NUMPAR <iNum>
/// @Param ProcName   Full name of the procedure.
/// @Param iNum       Number of parameters the procedure has.
/// @See SQL_SET_PROCEDURE_NAME SQL_SET_FUNCTION_NAME SQL_SET_PROCEDURE_PARAMETER
/// @See SQL_PROCEDURE_EXECUTE SQL_FUNCTION_EXECUTE SQL_GET_PROCEDURE_PARAMETER
/// @Example
/// // Assumes the following procedure exists (MySQL syntax):
/// // CREATE PROCEDURE simpleproc (OUT param1 INT)
/// //     BEGIN
/// //   SELECT COUNT(*) INTO param1 FROM SALESP;
/// // END
///
/// SQL_SET_PROCEDURE_NAME "simpleproc" NUMPAR 1
/// SQL_SET_PROCEDURE_PARAMETER 1 to iCount OUT
/// SQL_PROCEDURE_EXECUTE
/// SQL_GET_PROCEDURE_PARAMETER 1 to iCount
/// Showln " Salespeople count " iCount

#COMMAND SQL_SET_PROCEDURE_NAME R "NUMPAR" R
    DO_GETFILENUMBER_DRIVERNAME 0
    Move 0 to MertechInc_iParamCount
    INDICATE ERR False

    If      (MertechInc_DriverName = ORAFlex)   Send MertechInc_SQL_SET_ORAPROCEDURE_NAME !1 !3
    Else If (MertechInc_DriverName = MYSQLFLEX) Send MertechInc_SQL_SET_MYPROCEDURE_NAME !1 !3

    Move !3 to MertechInc_iParamCount  // Make sure MertechInc_iParamCount will have the proper value
#ENDCOMMAND

#Replace MDS_SET_PROCEDURE_NAME SQL_SET_PROCEDURE_NAME

Procedure MertechInc_SQL_SET_ORAPROCEDURE_NAME Global String strProcName Integer iNumpar
    Local Integer iParam

    Move 0 to MertechInc_iParamCount       //Redundant, but left in incase called
    INDICATE ERR False              //directly and not via SQL_SET_PROCEDURE_NAME
    Move ORAFlex to MertechInc_DriverName  //

    SQL_SET_STMT to "BEGIN "
    SQL_APPEND_STMT to strProcName
    SQL_APPEND_STMT to "( "
    For iParam from 1 to iNumpar
        DO_PASS_ARGUMENTS iParam
    Loop
    SQL_APPEND_STMT to  " ); END;"
    SQL_PREPARE_STMT
 End_Procedure

Procedure MertechInc_SQL_SET_MYPROCEDURE_NAME Global String strProcName Integer iNumpar
    Local Integer iParam

    Move 0 to MertechInc_iParamCount           //Redundant, but left in incase called
    INDICATE ERR False                  //directly and not via SQL_SET_PROCEDURE_NAME
    Move MySQLFlex to MertechInc_DriverName    //

    SQL_SET_STMT to "CALL "
    SQL_APPEND_STMT to strProcName
    SQL_APPEND_STMT to "("
    For iParam from 1 to iNumpar
        DO_PASS_ARGUMENTS iParam
    Loop
    SQL_APPEND_STMT to ")"
    SQL_PREPARE_STMT
End_Procedure

//=============================================================================
/// @Name        SQL_GET_STATEMENT
/// @Description Returns the embedded SQL statement that was last executed
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-09-21 By Ian Smith
///
/// @Syntax SQL_GET_STATEMENT TO <Variable> <Max> <Start>
/// @Param Variable  Variable to hold returned statement
/// @Param Max       Maximum number of characters to return
/// @Param Start     Start returning characters from
///
/// @Usage SQL_GET_STATEMENT TO sStatement 16000 0
/// @Usage SQL_GET_STATEMENT TO sStatement 1000 200
///
#COMMAND SQL_GET_STATEMENT "TO" #UGRLEC #L%U #L% .
    //MertechInc_iArg  - integer - Length (number of char to return)
    //MertechInc_iWork - integer - Start  (start character)
    #IF !0>2
        Move !3 to MertechInc_iArg   // Length

        #IF !0>3            // Start Position
            Move !4 to MertechInc_iWork
        #ELSE
            Move 0 to MertechInc_iWork
        #ENDIF
    #ELSE
        Move 0 to MertechInc_iArg
        Move 0 to MertechInc_iWork
    #ENDIF

    Get MertechInc_SQL_GET_STATEMENT MertechInc_iArg MertechInc_iWork to !2
#ENDCOMMAND

Function MertechInc_SQL_GET_STATEMENT Global Integer iLength Integer iStart Returns String
    Local String sStatement

    DO_GETFILENUMBER_DRIVERNAME 0

    If (MertechInc_FileNumber <> -1) Begin
        Get MertechInc_Pre_Size_String 0 to sStatement
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_GET_SQL_STMT CALLBACK 0 PASSING sStatement iStart iLength RESULT MertechInc_iRet
    End
    Function_Return sStatement
End_Function

//=============================================================================
/// @Name        SQL_SET_FUNCTION_NAME
/// @Description Sets the name of a stored function to execute
/// @Status      Public
/// @Drivers     ORAFLex, MySQLFlex, SQLFlex
/// @VersionNote Last Revised: 2009-09-19 By Ian Smith
///
/// @Syntax SQL_SET_FUNCTION_NAME <FuncName> NUMPAR <iNum>
/// @Param FuncName   Full name of the procedure.
/// @Param iNum       Number of parameters the function has.
/// @See SQL_SET_PROCEDURE_NAME SQL_SET_FUNCTION_NAME SQL_SET_PROCEDURE_PARAMETER
/// @See SQL_PROCEDURE_EXECUTE SQL_FUNCTION_EXECUTE SQL_GET_PROCEDURE_PARAMETER
/// @Example
///    Move '** NOT CHANGED **' to sPar1
///    Move 0                   to iPar2
///    Sysdate4                    dPar3
///
///    SQL_SET_FUNCTION_NAME "dbo.MDS_FUNC_TEST" NUMPAR 3
///    SQL_SET_FUNCTION_PARAMETER 1 to sPar1 IN
///    SQL_SET_FUNCTION_PARAMETER 2 to iPar2 IN
///    SQL_SET_FUNCTION_PARAMETER 3 to dPar3 IN
///    SQL_FUNCTION_EXECUTE
///    SQL_GET_FUNCTION_RETURN to sPar1
///
///    Showln 'sPar1: "' sPar1 '"'
///
#COMMAND SQL_SET_FUNCTION_NAME R "NUMPAR" R
    DO_GETFILENUMBER_DRIVERNAME 0
    MOVE 0 TO MertechInc_iParamCount
    INDICATE ERR FALSE

    If      (MertechInc_DriverName = ORAFlex)   Send MertechInc_SQL_SET_ORAFUNCTION_NAME !1 !3
    Else If (MertechInc_DriverName = MYSQLFLEX) Send MertechInc_SQL_SET_MYFUNCTION_NAME  !1 !3
    Else If (MertechInc_DriverName = SQLFLEX)   Send MertechInc_SQL_SET_SQLFUNCTION_NAME !1 !3

    // Make sure MertechInc_iParamCount will have the proper value
    If (MertechInc_DriverName = ORAFlex) MOVE (!3 + 1) TO MertechInc_iParamCount
    Else MOVE !3 TO MertechInc_iParamCount
#ENDCOMMAND

Procedure MertechInc_SQL_SET_ORAFUNCTION_NAME Global String strProcName Integer iNumpar
    Local Integer iParam

    SQL_SET_STMT to "BEGIN "
    SQL_APPEND_STMT to ":PAR_RET := "
    SQL_APPEND_STMT to strProcName
    SQL_APPEND_STMT to "( "
    For iParam from 1 to iNumpar
        DO_PASS_ARGUMENTS iParam
    Loop
    SQL_APPEND_STMT to  " ); END;"
    SQL_PREPARE_STMT

    Move IS_OUT to MertechInc_iArg
    Call_Driver 0 ORAFLEX Function CALLDRV_SET_PROC_ATTRIBUTE_TYPE CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank MertechInc_iArg RESULT MertechInc_iRet

    Increment MertechInc_iParamCount
    Move ":PAR_RET" to MertechInc_sArg2
    Call_Driver 0 MertechInc_DriverName Function 23 CALLBACK 0 PASSING MertechInc_Blank MertechInc_sArg2 16384 RESULT MertechInc_iRet
End_Procedure

Procedure MertechInc_SQL_SET_MYFUNCTION_NAME Global String strProcName Integer iNumpar
    Local Integer iParam

    Move MySQLFlex to MertechInc_DriverName

    SQL_SET_STMT to "SELECT "
    SQL_APPEND_STMT to strProcName
    SQL_APPEND_STMT to "("
    For iParam from 1 to iNumpar
        DO_PASS_ARGUMENTS iParam
    Loop
    SQL_APPEND_STMT to ")"
    SQL_PREPARE_STMT
End_Procedure

Procedure MertechInc_SQL_SET_SQLFUNCTION_NAME Global String strProcName Integer iNumpar
    Local Integer iParam

    Move SQLFlex to MertechInc_DriverName

    SQL_SET_STMT    to "SELECT "
    SQL_APPEND_STMT to strProcName
    SQL_APPEND_STMT to " ("
End_Procedure

//=============================================================================
/// @Name        SQL_SET_PROCEDURE_PARAMETER
/// @Description
/// With this command you can pass one or more parameters to predefined
/// stored procedures on a MySQL or Oracle server. The SQL_SET_PROCEDURE_PARAMETER
/// command enables you to add a parameter to a stored procedure which you are
/// planning to call. You can pass multiple parameters by calling the command
/// for each parameter.
///
/// When passing parameters you'll have to inform the driver which variable
/// you are passing, starting with 1 from left-to-right in the parameter list.
///
/// For each parameter you'll have to indicate if the variable is to be
/// regarded as input, output or both.
/// @Status      Public
/// @Drivers     ORAFLex, MySQLFlex
/// @VersionNote Last Revised: 2009-09-25 By Ian Smith
///
/// @Syntax SQL_SET_PROCEDURE_PARAMETER <iNum> TO <Var> <Direction>
/// @Param iNum      Number of the parameter to define
/// @Param Var       Value of the parameter
/// @Param Direction IN OUT IN_OUT RSET or Blank
/// @See SQL_SET_PROCEDURE_NAME SQL_SET_FUNCTION_NAME SQL_SET_PROCEDURE_PARAMETER
/// @See SQL_PROCEDURE_EXECUTE SQL_FUNCTION_EXECUTE SQL_GET_PROCEDURE_PARAMETER
/// @Example
/// SQL_SET_STMT       TO "CREATE PROCEDURE simpleproc2 (INOUT param1 INT, INOUT param2 INT)"
/// SQL_APPEND_STMT TO "BEGIN "
/// SQL_APPEND_STMT TO "DECLARE val INT;"
/// SQL_APPEND_STMT TO "set val = param1;"
/// SQL_APPEND_STMT TO "set param1 = param2;"
/// SQL_APPEND_STMT TO "set param2 = val;"
/// SQL_APPEND_STMT TO "END; "
/// SQL_PREPARE_STMT
/// SQL_EXECUTE_STMT
///
/// move 30 to sArg1
/// move 10 to sArg2
/// showln "> " sArg1 " < > " sArg2 " <"
///
/// SQL_SET_PROCEDURE_NAME "test.simpleproc2" NUMPAR 2
/// SQL_SET_PROCEDURE_PARAMETER 1 to sArg1 IN_OUT
/// SQL_SET_PROCEDURE_PARAMETER 2 to sArg2 IN_OUT
/// SQL_PROCEDURE_EXECUTE
/// SQL_GET_PROCEDURE_PARAMETER 1 to sArg1
/// SQL_GET_PROCEDURE_PARAMETER 2 to sArg2
///
/// showln "> " sArg1 " < > " sArg2 " <"
///
/// // An alternative way of calling the same SP
/// CALL_STORED_PROCEDURE "simpleproc2" PASSING sArg1 sArg2
/// showln "> " sArg1 " < > " sArg2 " <"

#COMMAND SQL_SET_PROCEDURE_PARAMETER R "TO" R """IN""OUT""IN_OUT""RSET"
    #IFTYPE !3 "D"
        Move DF_DATE to MertechInc_sArg1
    #ELSE
        Move " " to MertechInc_sArg1
    #ENDIF

    If (!1 <= MertechInc_iParamCount) Begin
        Move MertechInc_iParamCount to MertechInc_iSaveCount       // Save MertechInc_iParamCount
        Move (!1 -1) to MertechInc_iParamCount

        #IFDEF MertechInc_iArg
        #ELSE
            Integer MertechInc_iArg
        #ENDIF

        #IF (!0 = 4)
            #IFSAME !4 IN
                Move IS_IN to MertechInc_iArg
            #ELSE
                #IFSAME !4 OUT
                    Move IS_OUT to MertechInc_iArg
                #ELSE
                    #IFSAME !4 IN_OUT
                        Move IS_IN_OUT to MertechInc_iArg
                    #ELSE
                        Move IS_RSET to MertechInc_iArg
                    #ENDIF
                #ENDIF
            #ENDIF
        #ELSE
            Move IS_NONE to MertechInc_iArg
        #ENDIF

        Call_Driver 0 MertechInc_DriverName Function CALLDRV_SET_PROC_ATTRIBUTE_TYPE CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank MertechInc_iArg RESULT MertechInc_iRet

        DO_BIND_PARAMETERS !3
        Move MertechInc_iSaveCount to MertechInc_iParamCount
    End
    Else Begin
        Error 4099                  // Bad Parameter
    End
#ENDCOMMAND

#Replace MDS_SET_PROCEDURE_PARAMETER SQL_SET_PROCEDURE_PARAMETER

#COMMAND SQL_SET_FUNCTION_PARAMETER R "TO" R """IN""OUT""IN_OUT"
    #IF !0=4
        SQL_SET_PROCEDURE_PARAMETER !1 to !3 !4
    #ELSE
        SQL_SET_PROCEDURE_PARAMETER !1 to !3 IN
    #ENDIF
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_GET_PROCEDURE_PARAMETER
/// @Description Retrieves the value in the output parameter,
/// the value returned by the stored procedure, into the specified variable.
///
/// @Status      Public
/// @Drivers     ORAFLex, MySQLFlex
/// @VersionNote Last Revised: 2009-09-19 By Ian Smith
///
/// @Syntax SQL_GET_PROCEDURE_PARAMETER <Parameter> TO <Variable>
/// @Param Parameter The number of the parameter to retrieve
/// @Param Variable  Variable to hold the retrieved value
/// @See SQL_SET_PROCEDURE_NAME SQL_SET_FUNCTION_NAME SQL_SET_PROCEDURE_PARAMETER
/// @See SQL_PROCEDURE_EXECUTE SQL_FUNCTION_EXECUTE SQL_GET_PROCEDURE_PARAMETER
///
#COMMAND SQL_GET_PROCEDURE_PARAMETER R "TO" R
    IF (!1 <= MertechInc_iParamCount) BEGIN
        Move MertechInc_iParamCount to MertechInc_iSaveCount  // Save MertechInc_iParamCount
        MOVE (!1 -1) TO MertechInc_iParamCount
        DO_GET_BIND_PARAMETERS !3
        Move MertechInc_iSaveCount to MertechInc_iParamCount
    END
    ELSE BEGIN
        Error 4099  // Bad Parameter
    End
#ENDCOMMAND

#Replace MDS_GET_PROCEDURE_PARAMETER SQL_GET_PROCEDURE_PARAMETER

#COMMAND SQL_GET_FUNCTION_PARAMETER R "TO" R
    SQL_GET_PROCEDURE_PARAMETER (!1 + 1) TO !3
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_GET_FUNCTION_RETURN
/// @Description Get the result of a stored function into a DataFlex variable.
/// @Status      Public
/// @Drivers     ORAFLex, MySQLFlex, SQLFlex
/// @VersionNote Last Revised: 2009-09-19 By Ian Smith
///
/// @Syntax SQL_GET_FUNCTION_RETURN TO <Variable>
/// @Param Variable  Variable to hold the retrieved value
/// @See SQL_SET_PROCEDURE_NAME SQL_SET_FUNCTION_NAME SQL_SET_PROCEDURE_PARAMETER
/// @See SQL_PROCEDURE_EXECUTE SQL_FUNCTION_EXECUTE SQL_GET_PROCEDURE_PARAMETER
///
#COMMAND SQL_GET_FUNCTION_RETURN "TO" R
    Move MertechInc_iParamCount to MertechInc_iSaveCount  // Save MertechInc_iParamCount
    MOVE 0 TO MertechInc_iParamCount
    DO_GET_BIND_PARAMETERS !2
    Move MertechInc_iSaveCount to MertechInc_iParamCount
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_FUNCTION_EXECUTE
/// @Description Executes a MySQL stored function
/// @Status      Public
/// @Drivers     ORAFlex, MySQLFlex, SQLFlex
/// @VersionNote Last Revised: 2009-09-19 By Ian Smith
/// @See SQL_SET_PROCEDURE_NAME SQL_SET_FUNCTION_NAME SQL_SET_PROCEDURE_PARAMETER
/// @See SQL_PROCEDURE_EXECUTE SQL_FUNCTION_EXECUTE SQL_GET_PROCEDURE_PARAMETER
///
/// @Syntax SQL_FUNCTION_EXECUTE
///
#COMMAND SQL_FUNCTION_EXECUTE
    send MertechInc_SQL_FUNCTION_EXECUTE MertechInc_DriverName
#ENDCOMMAND

Procedure MertechInc_SQL_FUNCTION_EXECUTE Global String sDriverName
    Local Integer iParam
    Local String  sParam sSTMT

    If (sDriverName = SQLFLEX) Begin
       For iParam from 0 to (MertechInc_iParamCount - 1)
           Get MertechInc_DO_GET_BIND_PARAMETERS False MertechInc_Blank MertechInc_Blank iParam to sParam

           SQL_APPEND_STMT to "'"
           SQL_APPEND_STMT to sParam
           SQL_APPEND_STMT to "'"

           If (iParam < (MertechInc_iParamCount - 1)) Begin
              SQL_APPEND_STMT to ','
           End
       Loop

       SQL_APPEND_STMT to ')'
       SQL_PREPARE_STMT
    End

    SQL_EXECUTE_STMT
    If (sDriverName = MYSQLFLEX or sDriverName = SQLFLEX) Begin
        SQL_FETCH_NEXT_ROW
    End
End_Procedure

//=============================================================================
/// @Name        REEXEC_ORACLE_STORED_PROCEDURE
/// @Description Re-executes the current Oracle stored procedure
/// @Status      Public
/// @Drivers     ORAFLex
/// @VersionNote Last Revised: 2009-09-19 By Ian Smith
/// @VersionNote Last Revised: 2009-12-04 By Marcelo Nachbar
///
/// @Syntax CALL_ORACLE_STORED_PROCEDURE <ProcName> {PASSING <Arg1> {. <Argn>}}
/// @Param ProcName   Full name of the procedure.
/// @Param Arg1.Argn  Arguments passed to the procedure.
/// @See CALL_STORED_PROCEDURE
///
#COMMAND REEXEC_ORACLE_STORED_PROCEDURE R "PASSING"""
    MOVE 0 TO MertechInc_iParamCount
    SQL_SET_STMT TO " "
    INDICATE ERR FALSE
    #IF (!0>2)
        DO_PASS_ARGUMENTS !3 !4 !5 !6 !7 !8 !9
        [ NOT ERR ] BEGIN
            IF MertechInc_iParamCount GT 0 BEGIN
                MOVE 0 TO MertechInc_iParamCount
                DO_BIND_PARAMETERS !3 !4 !5 !6 !7 !8 !9
            END
        END
    #ENDIF
    //SQL_EXECUTE_STMT
    Move 1 to MertechInc_sArg1         // Initialize the Row_Count value
    Call_Driver MertechInc_FileNumber MertechInc_DriverName Function 22 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 5 RESULT MertechInc_iRet
    If MertechInc_iRet EQ -1 INDICATE ERR True
    [ NOT ERR ] BEGIN
        If ( MertechInc_iParamCount GT 0 ) BEGIN
            MOVE 0 TO MertechInc_iParamCount
            DO_GET_BIND_PARAMETERS !3 !4 !5 !6 !7 !8 !9
        END
    END
#ENDCOMMAND

#COMMAND REEXEC_STORED_PROCEDURE R "PASSING"""
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        REEXEC_ORACLE_STORED_PROCEDURE !1 !2 !3 !4 !5 !6 !7 !8 !9
    End
#ENDCOMMAND

//=============================================================================
/// @Name        CALL_STORED_PROCEDURE
/// @Description Executes a stored procedure
/// @Status      Public
/// @Drivers     SQLFlex ORAFLex MySQLFlex
/// @VersionNote Last Revised: 2009-09-19 By Ian Smith
///
/// @Syntax CALL_STORED_PROCEDURE <ProcName> {Passing <Arg1> {... <Argn>}}
/// @Param See driver specific calls
/// @Example
/// // This example uses an Oracle stored procedure
/// SQL_SET_STMT    TO 'CREATE OR REPLACE PROCEDURE "SET_CUST_CREDLIM2" '
/// SQL_APPEND_STMT TO ' ( LimIN in number, RowC out integer) IS '
/// SQL_APPEND_STMT TO ' BEGIN '
/// SQL_APPEND_STMT TO '    UPDATE CUSTOMER SET CUSTOMER.CREDIT_LIMIT = LimIN; '
/// SQL_APPEND_STMT TO '    RowC := SQL%ROWCOUNT; '
/// SQL_APPEND_STMT TO ' END; '
/// SQL_PREPARE_STMT
/// SQL_EXECUTE_STMT
///
/// SQL_SET_STMT    TO 'ALTER TABLE CUSTOMER ADD(CONSTRAINT CK_CREDLIM CHECK(CREDIT_LIMIT >= 200)) '
/// SQL_PREPARE_STMT
/// SQL_EXECUTE_STMT
///
/// INTEGER LIMCRED RET
/// string errorstring
/// MOVE 5000 TO LIMCRED
///
/// SQL_START_TRANSACTION_STMT
///
/// CALL_STORED_PROCEDURE "SET_CUST_CREDLIM2" passing LIMCRED RET
///
///   [ ERR ] begin
///       SQL_ERROR_MESSAGE errorString
///       SHOWLN errorString
///       SQL_ROLLBACK_STMT
///       PAUSE
///       ABORT
///   end
///
/// SQL_COMMIT_STMT
///
/// showln "PROCEDURE EXECUTED"
/// showln "Limit Credit " LIMCRED
/// showln "Total Lines Modified equals " RET
///
///   MOVE 100 TO LIMCRED
///
///   SQL_START_TRANSACTION_STMT
///
///   // Only valid for Oracle, for other databases, use CALL_STORED_PROCEDURE again
///   REEXEC_STORED_PROCEDURE "SET_CUST_CREDLIM2" passing LIMCRED RET
///   [ ERR ] begin
///       SQL_ERROR_MESSAGE errorString
///       SHOWLN errorString
///       SQL_ROLLBACK_STMT
///       PAUSE
///       ABORT
///   end
///
/// SQL_COMMIT_STMT
///
/// showln "PROCEDURE RE-EXECUTED"
/// showln "Limit Credit " LIMCRED
/// showln "Total Lines Modified equals " RET

#COMMAND CALL_STORED_PROCEDURE R "PASSING""BINDING"""
    DO_GETFILENUMBER_DRIVERNAME 0

    If      (MertechInc_DriverName EQ MySQLFlex) CALL_MYSQL_STORED_PROCEDURE  !1 !2 !3 !4 !5 !6 !7 !8 !9
    Else If (MertechInc_DriverName EQ SQLFlex)   CALL_SQLSERVER_PROCEDURE     !1 !2 !3 !4 !5 !6 !7 !8 !9
    Else                                         CALL_ORACLE_STORED_PROCEDURE !1 !2 !3 !4 !5 !6 !7 !8 !9
#ENDCOMMAND

//=============================================================================
/// @Name        CALL_STORED_FUNCTION
/// @Description Executes a stored function and returns the value
/// @Status      Public
/// @Drivers     ORAFLex MySQLFlex PgFlex
/// @VersionNote Last Revised: 2009-09-19 By Ian Smith
///
/// @Syntax CALL_STORED_FUNCTION
/// @Param ProcName   Full name of the procedure.
/// @Param Arg1.Argn  Arguments passed to the procedure.
/// @Example
/// // This example uses Oracle
/// SQL_SET_STMT    TO 'CREATE OR REPLACE FUNCTION "FEXEC_CURSOR2" '
/// SQL_APPEND_STMT TO ' (nVAR1 varchar2) RETURN NUMBER '
/// SQL_APPEND_STMT TO ' IS '
/// SQL_APPEND_STMT TO '   nGTotal CUSTOMER.PURCHASES%TYPE; '
/// SQL_APPEND_STMT TO '   BEGIN '
/// SQL_APPEND_STMT TO '     nGTotal := 0; '
/// SQL_APPEND_STMT TO '     DECLARE '
/// SQL_APPEND_STMT TO '        CURSOR uCUSTOMER IS SELECT RECNUM, STATE, PURCHASES FROM CUSTOMER; '
/// SQL_APPEND_STMT TO '     BEGIN '
/// SQL_APPEND_STMT TO '        FOR x IN uCUSTOMER LOOP '
/// SQL_APPEND_STMT TO "           IF x.STATE=nVAR1 THEN "
/// SQL_APPEND_STMT TO '              nGTotal := (nGtotal + x.PURCHASES); '
/// SQL_APPEND_STMT TO '           END IF; '
/// SQL_APPEND_STMT TO '        END LOOP; '
/// SQL_APPEND_STMT TO '     END; '
/// SQL_APPEND_STMT TO '     return nGTotal; '
/// SQL_APPEND_STMT TO '   exception '
/// SQL_APPEND_STMT TO '     when others then null; '
/// SQL_APPEND_STMT TO '   end; '
/// SQL_PREPARE_STMT
/// SQL_EXECUTE_STMT
///
/// string nVar1 ERR_MSG
/// integer nTotal
///
/// move 0    to ntotal
/// move "CA" to nVar1
///
/// CALL_STORED_FUNCTION "FEXEC_CURSOR2" RETURNS nTotal Passing nVar1
/// [ ERR ] BEGIN
///      SQL_ERROR_MESSAGE ERR_MSG
///      SHOWLN "ERROR :> " ERR_MSG
/// END
///
/// [ NOT ERR ] SHOWLN "FUNCTION EXECUTED"
/// SHOWLN
/// showln "State = " nVar1
/// SHOWLN "Total = " nTotal
///
/// move "FL" to nVar1
/// CALL_STORED_FUNCTION "FEXEC_CURSOR2" RETURNS nTotal Passing nVar1
/// [ ERR ] BEGIN
///      SQL_ERROR_MESSAGE ERR_MSG
///      SHOWLN "ERROR :> " ERR_MSG
/// END
/// [ NOT ERR ] SHOWLN "FUNCTION re-EXECUTED"
/// SHOWLN
/// SHOWLN "State = " nVar1
/// SHOWLN "Total = " nTotal

#COMMAND CALL_STORED_FUNCTION R "RETURNS" R "PASSING"""
    DO_GETFILENUMBER_DRIVERNAME 0

    If      (MertechInc_DriverName EQ MDSPGSQL)  CALL_PGSQL_STORED_FUNCTION  !1 !2 !3 !4 !5 !6 !7 !8 !9
    Else If (MertechInc_DriverName EQ MySQLFlex) CALL_MYSQL_STORED_FUNCTION  !1 !2 !3 !4 !5 !6 !7 !8 !9
    Else                                         CALL_ORACLE_STORED_FUNCTION !1 !2 !3 !4 !5 !6 !7 !8 !9
#ENDCOMMAND

//=============================================================================
/// @Name        OUTPUT_INT_FILE
/// @Description Generates an .INT file from an opened table.
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-12 By Ian Smith
///
/// @Syntax OUTPUT_INT_FILE FOR <FileNo|FileName> TO <IntFileName>
/// @Param FileNum      is the File Number
/// @Param FileName     is the File Name
/// @Param IntFileName  Full path of INT file
/// @Example
/// // SALES table is been opened without using an INT file. OUTPUT_INT_FILE
/// // will create an INT file named sales.int that can be used later for opening this table.
/// // open ("ORA_DRV:/"+"/USERNAME*SALES") as FLEXERRS
/// OUTPUT_INT_FILE for FLEXERRS.FILE_NUMBER to "C:\TEMP\SALES.INT"

#COMMAND OUTPUT_INT_FILE "FOR" R "TO" R .
    DO_GETFILENUMBER_DRIVERNAME !2
    If (MertechInc_FileNumber <> -1) Begin
        MOVE !4 TO MertechInc_sArg1

        IF (MertechInc_DriverName EQ ORAFLEX OR MertechInc_DriverName EQ MDSDB2) ;
            Call_Driver MertechInc_FileNumber MertechInc_DriverName Function 19 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 0 RESULT MertechInc_iRet
        ELSE ;
            Call_Driver MertechInc_FileNumber MertechInc_DriverName Function 16 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 0 RESULT MertechInc_iRet
        IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
    END
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_ERROR_MESSAGE
/// @Description Fetches native database error into a variable.
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-14 By Ian Smith
/// @See         SQL_ERROR_MESSAGE SQL_ERROR_MESSAGE2
///
/// @Syntax SQL_ERROR_MESSAGE <Variable>
/// @Param Variable  Variable for the returned error message
///
#COMMAND SQL_ERROR_MESSAGE R .
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        Get MertechInc_SQL_ERROR_MESSAGE to !1

        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

Function MertechInc_SQL_ERROR_MESSAGE Global Returns String
    Local String sMessage

    Get MertechInc_Pre_Size_String 0 to sMessage
    Call_Driver 0 MertechInc_DriverName Function CALLDRV_SQL_ERROR_MESSAGE CALLBACK 0 PASSING MertechInc_Blank sMessage 0 RESULT MertechInc_iRet

    Function_Return sMessage
End_Function

//=============================================================================
/// @Name        SQL_ERROR_MESSAGE2
/// @Description Fetches the last error for the specified server
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-09-19 By Ian Smith
/// @See         SQL_ERROR_MESSAGE SQL_ERROR_MESSAGE2
///
/// @Syntax SQL_ERROR_MESSAGE2 "OF" <Server> "TO" <Variable>
/// @Param Server    Name of the server to get error test from
/// @Param Variable  Variable for the returned error message
///
#COMMAND SQL_ERROR_MESSAGE2 "OF" R "TO" R .
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        Get MertechInc_SQL_ERROR_MESSAGE2 !2 to !4
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

Function MertechInc_SQL_ERROR_MESSAGE2 Global String sServer Returns String
    Local String sMessage

    Get MertechInc_Pre_Size_String 800 to sMessage
    Call_Driver 0 MertechInc_DriverName Function CALLDRV_SQL_ERROR_MESSAGE2 CALLBACK 0 PASSING sServer sMessage 0 RESULT MertechInc_iRet

    Function_Return sMessage
End_Function

//=============================================================================
/// @Name        MERTECH_WARNING_MESSAGE
/// @Description When restructuring a table, enables or disables warning messages.
///
/// By default the driver will pop up a warning message that a restructuring
/// operation is about to take place.
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-14 By Ian Smith
///
/// @Syntax MERTECH_WARNING_MESSAGE Enabled|Disabled
///
#COMMAND MERTECH_WARNING_MESSAGE "ENABLED""DISABLED" .
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        #IFSAME !1 DISABLED
            CALL_DRIVER 0 MertechInc_DriverName  FUNCTION 34 CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 1 RESULT MertechInc_iRet
        #ELSE
            CALL_DRIVER 0 MertechInc_DriverName  FUNCTION 34 CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 0 RESULT MertechInc_iRet
        #ENDIF
    End
#ENDCOMMAND

//=============================================================================
/// @Name        DISABLE_SELECT_COLUMNS_ERRORS
/// @Description When restructuring a table, enables or disables warning messages.
/// @Status      Internal
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-14 By Ian Smith
///
/// @Syntax DISABLE_SELECT_COLUMNS_ERRORS Enabled|Disabled
///
#COMMAND DISABLE_SELECT_COLUMNS_ERRORS "ENABLED""DISABLED" .
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        #IFSAME !1 DISABLED
            CALL_DRIVER 0 MertechInc_DriverName  FUNCTION 35 CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 1 RESULT MertechInc_iRet
        #ELSE
            CALL_DRIVER 0 MertechInc_DriverName  FUNCTION 35 CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 0 RESULT MertechInc_iRet
        #ENDIF
    End
#ENDCOMMAND

//=============================================================================
/// @Name        SQLFlex_REVISION
/// @Description Retrieves the SQLFlex version currently in use.
/// @Status      Public
/// @Drivers     SQLFlex
/// @VersionNote Last Revised: 2009-08-14 By Ian Smith
/// @See SQLFlex_REVISION SQLFlex_MAJOR_REVISION
///
/// @Syntax SQLFlex_REVISION <Var>
/// @Param Var Variable to receive the attribute
///
#COMMAND SQLFlex_REVISION #CRUG .
    INDICATE ERR False
    Move (Repeat(" ",255)) to !1
    Call_Driver 0 SQLFlex Function 0 CALLBACK 0 PASSING MertechInc_Blank !1 0 RESULT MertechInc_iRet
    If MertechInc_iRet EQ -1 INDICATE ERR True
#ENDCOMMAND

//=============================================================================
/// @Name        SQLFlex_MAJOR_REVISION
/// @Description Retrieves SQLFlex major revision.
/// @Status      Public
/// @Drivers     SQLFlex
/// @VersionNote Last Revised: 2009-08-14 By Ian Smith
/// @See SQLFlex_REVISION SQLFlex_MAJOR_REVISION
///
/// @Syntax SQLFlex_MAJOR_REVISION <Var>
/// @Param Var Variable to receive the attribute
///
#COMMAND SQLFlex_MAJOR_REVISION #CRUG .
    INDICATE ERR False
    Move (Repeat(" ",10)) to MertechInc_sArg2
    Call_Driver 0 SQLFlex Function 0 CALLBACK 0 PASSING MertechInc_Blank MertechInc_sArg2 4 RESULT MertechInc_iRet
    If MertechInc_iRet EQ -1 INDICATE ERR True
    Else Move MertechInc_sArg2 to !1
#ENDCOMMAND

//=============================================================================
/// @Name        LOGGED_USERS
/// @Description Returns the current number of users logged on to the SQL backend
/// using the driver.
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-14 By Ian Smith
/// @See LOGGED_USERS MAXIMUM_NUMBER_OF_USERS
///
/// @Syntax LOGGED_USERS <Var>
/// @Param Var Variable to receive the attribute
///
#COMMAND LOGGED_USERS #CRUG .
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        Call_Driver 0 MertechInc_DriverName Function 33 CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 0 RESULT MertechInc_iRet
        MOVE MertechInc_iRet TO !1
    End
#ENDCOMMAND

//=============================================================================
/// @Name        MAXIMUM_NUMBER_OF_USERS
/// @Description Returns the maximum number of users the license in use allows
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-14 By Ian Smith
/// @See LOGGED_USERS MAXIMUM_NUMBER_OF_USERS
///
/// @Syntax MAXIMUM_NUMBER_OF_USERS <Var>
/// @Param Var Variable to receive the attribute
///
#COMMAND MAXIMUM_NUMBER_OF_USERS #CRUG .
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        INDICATE ERR FALSE
        Move (Repeat(" ",10)) to MertechInc_sArg2
        CALL_DRIVER 0 MertechInc_DriverName FUNCTION 0 CALLBACK 0 PASSING MertechInc_Blank MertechInc_sArg2 3 RESULT MertechInc_iRet
        IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
        Else Move MertechInc_sArg2 to !1
    End
#ENDCOMMAND

//=============================================================================
/// @Name        SET_DATABASE_NAME
/// @Description
/// Defines the current database name to be used by the driver when opening an
/// INT file without a DATABASE_SPACE_NAME token.
///
/// If there is a DATABASE_SPACE_NAME token in the INT file, that will control the databse used.
/// If there is no token and SET_DATABASE_NAME has not been called, the default
/// database of the login will be used.
///
/// After calling SET_DATABASE_NAME any subsequent OPEN calls for tables
/// without a DATABASE_SPACE_NAME token will use the database set.
///
/// To control the current database for embedded SQL calls use SQL_USE_DATABASE
///
/// @Status      Public
/// @Drivers     SQLFlex, MySQLFlex & PgFlex
/// @VersionNote Last Revised: 2009-08-14 By Ian Smith
/// @See SET_DATABASE_NAME GET_DATABASE_NAME SQL_USE_DATABASE
///
/// @Syntax SET_DATABASE_NAME TO <databasename>
/// @Param databasename The new name of the current database.
///
#COMMAND SET_DATABASE_NAME "TO" R .
    DO_GETFILENUMBER_DRIVERNAME 0
    INDICATE ERR FALSE
    IF (MertechInc_DriverName EQ SQLFLEX OR MertechInc_DriverName EQ MDSMySQL OR MertechInc_DriverName EQ MDSPgSQL) BEGIN
        MOVE !2 TO MertechInc_sArg1
        CALL_DRIVER 0 MertechInc_DriverName FUNCTION 9 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 0 RESULT MertechInc_iRet
        IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
    END
#ENDCOMMAND

//=============================================================================
/// @Name        GET_DATABASE_NAME
/// @Description Get the name of the database currently in use when
/// opening tables without a DATABASE_SPACE_NAME token.
///
/// @Status      Public
/// @Drivers     SQLFlex, MySQLFlex & PgFlex
/// @VersionNote Last Revised: 2009-08-14 By Ian Smith
/// @See SET_DATABASE_NAME GET_DATABASE_NAME SQL_USE_DATABASE
///
/// @Syntax GET_DATABASE_NAME TO <Var>
/// @Param Var Variable to receive the attribute
///
#COMMAND GET_DATABASE_NAME "TO" #CRUG .
    DO_GETFILENUMBER_DRIVERNAME 0
    INDICATE ERR FALSE
    IF (MertechInc_DriverName EQ SQLFLEX OR MertechInc_DriverName EQ MDSMySQL OR MertechInc_DriverName EQ MDSPgSQL) BEGIN
        MOVE (REPEAT(" ",255)) to MertechInc_sArg1
        CALL_DRIVER 0 MertechInc_DriverName FUNCTION 9 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 1 RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
        [  ERR ] Move ""               to !2
        [ ~ERR ] Move MertechInc_sArg1 to !2
    END
#ENDCOMMAND

//=============================================================================
/// @Name        SET_SCHEMA_NAME
/// @Description Defines the schema name to be used when opening tables
/// that do not have a SCHEMA_NAME token in the INT file.
/// The default if there is no schema name set is to use the logged in user's
/// default schema.
///
/// @Status      Public
/// @Drivers     SQLFlex & ORAFlex
/// @VersionNote Last Revised: 2009-08-14 By Ian Smith
/// @See SET_SCHEMA_NAME GET_SCHEMA_NAME
///
/// @Syntax SET_SCHEMA_NAME TO <SchemaName>
/// @Param SchemaName New schema name
///
#COMMAND SET_SCHEMA_NAME "TO" R .
    DO_GETFILENUMBER_DRIVERNAME 0
    INDICATE ERR FALSE
    MOVE !2 TO MertechInc_sArg1
    If MertechInc_DriverName EQ SQLFLEX      Call_Driver 0 SQLFlex Function 10 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 0 RESULT MertechInc_iRet
    Else If MertechInc_DriverName EQ ORAFLEX Call_Driver 0 ORAFlex Function  8 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 0 RESULT MertechInc_iRet
    IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
#ENDCOMMAND

//=============================================================================
/// @Name        GET_SCHEMA_NAME
/// @Description Get the current schema name that is used when opening tables
/// that do not have a SCHEMA_NAME token in the INT file.
///
/// @Status      Public
/// @Drivers     SQLFlex & ORAFlex
/// @VersionNote Last Revised: 2009-08-14 By Ian Smith
/// @See SET_SCHEMA_NAME GET_SCHEMA_NAME
///
/// @Syntax SET_SCHEMA_NAME TO <SchemaName>
/// @Param SchemaName New schema name
///
#COMMAND GET_SCHEMA_NAME "TO" #CRUG .
    DO_GETFILENUMBER_DRIVERNAME 0
    INDICATE ERR FALSE
    MOVE (REPEAT(" ",255)) to MertechInc_sArg1
    If MertechInc_DriverName EQ SQLFLEX Call_Driver 0 SQLFlex Function 10 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 1 RESULT MertechInc_iRet
    Else                                Call_Driver 0 ORAFlex Function  8 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 1 RESULT MertechInc_iRet
    IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
    [  ERR ] MOVE ""     TO !2
    [ ~ERR ] MOVE MertechInc_sArg1 TO !2
#ENDCOMMAND

//=============================================================================
/// @Name        GET_NAME_SPACE
/// @Description Get the current PostgreSQL schema (name space).
/// @Status      Public
/// @Drivers     PgFlex
/// @VersionNote Last Revised: 2009-08-14 By Ian Smith
///
/// @Syntax GET_NAME_SPACE TO <Variable>
/// @Param Variable is a variable to keep retrieved value
///
#COMMAND GET_NAME_SPACE "TO" #CRUG .
    DO_GETFILENUMBER_DRIVERNAME 0
    INDICATE ERR False
    MOVE (REPEAT(" ",255)) to MertechInc_sArg1
    If MertechInc_DriverName EQ PGFLEX Call_Driver 0 PGFLEX Function CALLDRV_PGSQL_NAME_SPACE CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 0 RESULT MertechInc_iRet
    IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
    [  ERR ] MOVE ""     TO !2
    [ ~ERR ] MOVE MertechInc_sArg1 TO !2
#ENDCOMMAND

//=============================================================================
/// @Name        SET_NAME_SPACE
/// @Description Set the current PostgreSQL schema (name space).
/// @Status      Public
/// @Drivers     PgFlex
/// @VersionNote Last Revised: 2009-08-14 By Ian Smith
///
/// @Syntax SET_NAME_SPACE TO <Value>
/// @Param Value is the PostgreSQL schema (name space) you want to set
///
#COMMAND SET_NAME_SPACE "TO" R .
    DO_GETFILENUMBER_DRIVERNAME 0
    INDICATE ERR False
    IF MertechInc_DriverName EQ PGFLEX BEGIN
        Move !2 to MertechInc_sArg1
        Call_Driver 0 PGFLEX Function CALLDRV_PGSQL_NAME_SPACE CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 1 RESULT MertechInc_iRet
        IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
    END
    ELSE INDICATE ERR TRUE
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_USE_DATABASE
/// @Description Specifies the database to use when executing embedded SQL
/// statements, if object names are not fully qualified.
///
/// @Status      Public
/// @Drivers     SQLFlex MySQLFLex PgSQL
/// @VersionNote Last Revised: 2009-09-22 By Ian Smith
///
/// @Comment SQLFlex MySQLFLex PgSQL
/// @Syntax SQL_USE_DATABASE <Database> (SQLFlex MySQLFlex PgFlex)
/// @Param Database  Name of the database to use
///
/// @Comment only MySQLFLex PgSQL (not SQLFlex)
/// @Syntax SQL_USE_DATABASE OF <Server> TO <Database> (PgFlex only)
/// @Param Database  Name of the database to use
/// @See SET_DATABASE_NAME SQL_USE_DATABASE
///
#COMMAND SQL_USE_DATABASE
    DO_GETFILENUMBER_DRIVERNAME 0

    #IFSAME !1 of
        #CHECK !3 "TO"
        Move !2 to MertechInc_sArg2
        Move !4 to MertechInc_sArg1
    #ELSE
        Move !1      to MertechInc_sArg1
        Move MertechInc_Blank to MertechInc_sArg2
    #ENDIF
    If (MertechInc_DriverName EQ SQLFLEX or MertechInc_DriverName EQ MDSMySQL or MertechInc_DriverName EQ MDSPgSQL) Begin
        Call_Driver 0 MertechInc_DriverName Function 18 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_sArg2 0 RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        SET_CURRENT_SQL_SERVER
/// @Description Set name of the server that will be used to open tables
/// if there is no SERVER_NAME token in the INT file.
///
/// To control the server used for embedded SQL, use SET_CURRENT_SQL_SERVER_CONNECTION
///
/// This function is only needed if you connect to multiple SQL servers.
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-14 By Ian Smith
/// @See GET_CURRENT_SQL_SERVER SET_CURRENT_SQL_SERVER SET_CURRENT_SQL_SERVER_CONNECTION GET_CURRENT_SQL_SERVER_CONNECTION
///
/// @Syntax SET_CURRENT_SERVER TO <servername>
/// @Param servername      Name of the server
///
#COMMAND SET_CURRENT_SQL_SERVER "TO" R .
    INDICATE ERR FALSE
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        If MertechInc_DriverName EQ ORAFLEX Move CALLDRV_ORA_CURRENT_SQL_SERVER to MertechInc_iFunction
        Else                                Move CALLDRV_CURRENT_SQL_SERVER     to MertechInc_iFunction
        Move !2 to MertechInc_sArg1
        Call_Driver 0 MertechInc_DriverName Function MertechInc_iFunction CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 0 RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

//IGS - removed. CURRENT_SERVER is a property of Validation_List_Mixin so this
//               replace conflicts with the property SET message.
//#Replace SET_CURRENT_SERVER SET_CURRENT_SQL_SERVER

//=============================================================================
/// @Name        GET_CURRENT_SQL_SERVER
/// @Description Retrieve name of the server that will be used to open tables
/// if there is no SERVER_NAME token in the INT file.
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-14 By Ian Smith
/// @See GET_CURRENT_SQL_SERVER SET_CURRENT_SQL_SERVER SET_CURRENT_SQL_SERVER_CONNECTION GET_CURRENT_SQL_SERVER_CONNECTION
///
/// @Syntax GET_CURRENT_SERVER TO <servername>
/// @Param servername      Variable to receive the name of the server
///
#COMMAND GET_CURRENT_SQL_SERVER "TO" #CRUG .
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        Move (Repeat(" ",255)) to MertechInc_sArg1
        If MertechInc_DriverName EQ ORAFLEX Move CALLDRV_ORA_CURRENT_SQL_SERVER to MertechInc_iFunction
        Else                                Move CALLDRV_CURRENT_SQL_SERVER     to MertechInc_iFunction
        Call_Driver 0 MertechInc_DriverName Function MertechInc_iFunction CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 1 RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
        [  ERR ] Move ""     to !2
        [ ~ERR ] Move MertechInc_sArg1 to !2
    End
#ENDCOMMAND

//IGS - removed. CURRENT_SERVER is a property of Validation_List_Mixin so this
//               replace conflicts with the property GET message.
//#Replace GET_CURRENT_SERVER GET_CURRENT_SQL_SERVER


//=============================================================================
/// @Name        SET_CURRENT_SQL_SERVER_CONNECTION
/// @Description Specify which server connection that should be used to execute
/// embedded SQL commands. By default the last logged into server is used.
///
/// This function is only needed if you connect to multiple SQL servers.
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2010-12-17 By Marcelo
/// @See GET_CURRENT_SQL_SERVER SET_CURRENT_SQL_SERVER SET_CURRENT_SQL_SERVER_CONNECTION GET_CURRENT_SQL_SERVER_CONNECTION
///
/// @Syntax SET_CURRENT_SQL_SERVER_CONNECTION OF <drivername> TO <servername>
/// @Param drivername      Name of the driver {MYSQLFLEX | ORAFLEX | PGFLEX | SQLFLEX }
/// @Param servername      Name of the server used during the initial LOGIN
///
/// @Usage SET_CURRENT_SQL_SERVER_CONNECTION of SQLFlex   To "LOCALHOST/SQLSERVER2008"
/// @Usage SET_CURRENT_SQL_SERVER_CONNECTION of MYSQLFlex To "LOCALHOST"
/// @Usage SET_CURRENT_SQL_SERVER_CONNECTION of MYSQLFlex To ""

#COMMAND SET_CURRENT_SQL_SERVER_CONNECTION "OF" R "TO" R .
    INDICATE ERR FALSE

    #IFSAME !2 MYSQLFLEX
    #ELSE
      #IFSAME !2 ORAFLEX
      #ELSE
        #IFSAME !2 PGFLEX
        #ELSE
          #IFSAME !2 SQLFLEX
          #ELSE
            #ERROR 4099 "Invalid parameter"
          #ENDIF
        #ENDIF
      #ENDIF
    #ENDIF

    Move (Uppercase(Trim(!2))) to MertechInc_DriverName

    If (Trim(!4) > "") Move !2 to MertechInc_CurrentDriver
    Else               Move "" to MertechInc_CurrentDriver
    Move !4 to MertechInc_sArg1
    Call_Driver 0 MertechInc_DriverName Function CALLDRV_CURRENT_SQL_SERVER_CONNECTION CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 0 RESULT MertechInc_iRet
    If MertechInc_iRet EQ -1 INDICATE ERR True
#ENDCOMMAND

//=============================================================================
/// @Name        GET_CURRENT_SQL_SERVER_CONNECTION
/// @Description Retrieve which server connection is used to execute
/// embedded SQL commands.
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2010-12-17 By Marcelo
/// @See GET_CURRENT_SQL_SERVER SET_CURRENT_SQL_SERVER SET_CURRENT_SQL_SERVER_CONNECTION GET_CURRENT_SQL_SERVER_CONNECTION
///
/// @Syntax GET_CURRENT_SQL_SERVER_CONNECTION OF <drivername> TO <servername>
/// @Param drivername      Name of the driver {MYSQLFLEX | ORAFLEX | PGFLEX | SQLFLEX }
/// @Param servername      Variable to receive the name of the server
///
/// @Usage GET_CURRENT_SQL_SERVER_CONNECTION of SQLFlex To lsServerName
/// @Usage GET_CURRENT_SQL_SERVER_CONNECTION of ORAFlex To lsServerName

#COMMAND GET_CURRENT_SQL_SERVER_CONNECTION "OF" R "TO" #CRUG .
    INDICATE ERR FALSE

    #IFSAME !2 MYSQLFLEX
    #ELSE
      #IFSAME !2 ORAFLEX
      #ELSE
        #IFSAME !2 PGFLEX
        #ELSE
          #IFSAME !2 SQLFLEX
          #ELSE
            #ERROR 4099 "Invalid parameter"
          #ENDIF
        #ENDIF
      #ENDIF
    #ENDIF

    Move (Repeat(" ",255)) to MertechInc_sArg1
    Move !2 to MertechInc_sArg2
    Call_Driver 0 MertechInc_sArg2 Function CALLDRV_CURRENT_SQL_SERVER_CONNECTION CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 1 RESULT MertechInc_iRet
    If MertechInc_iRet EQ -1 INDICATE ERR True
    [  ERR ] Move ""               to !4
    [ ~ERR ] Move MertechInc_sArg1 to !4
#ENDCOMMAND

//=============================================================================
/// @Name        LOGIN_SQLFLEX
/// @Description This login command allows the user to specify the
/// host name when logging in. The hostname shows up in master.dbo.sysprocesses.
/// @Status      Public
/// @Drivers     SQLFlex
/// @VersionNote Last Revised: 2009-08-14 By Ian Smith
///
/// @Syntax LOGIN_SQLFLEX <ServerName> <UserName> <Password> <HostName>
/// @Param ServerName   Server Name Login into
/// @Param UserName     User who is Login in
/// @Param Password     Users password
/// @Param HostName     Host Name Login into.
///
#COMMAND LOGIN_SQLFLEX #ULGR$ #ULGR$ #ULGR$ #ULG$ .
  LOGIN (!1+"*"+!4) !2 !3 "SQL_DRV"
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_CANCEL_QUERY_STMT
/// @Description Closes the current embedded SQL cursor.
/// This command should be executed after all SQL_EXECUTE_STMT
/// commands that retrieve rows, after the rows have been fetched.
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-14 By Ian Smith
///
/// @Syntax SQL_CANCEL_QUERY_STMT {of <File Name|File No>}
/// @Param FileNum      is the File Number
/// @Param FileName     is the File Name
/// @See SQL_SET_STMT SQL_APPEND_STMT SQL_PREPARE_STMT SQL_EXECUTE_STMT SQL_CANCEL_QUERY_STMT SQL_FETCH_NEXT_ROW
///
/// @Usage SQL_CANCEL_QUERY_STMT of file1
/// @Usage SQL_CANCEL_QUERY_STMT
///
#COMMAND SQL_CANCEL_QUERY_STMT """OF"
    #IF (!0>1)
        DO_GETFILENUMBER_DRIVERNAME !2
    #ELSE
        DO_GETFILENUMBER_DRIVERNAME 0
    #ENDIF
    If (MertechInc_FileNumber <> -1) Begin
        Call_Driver MertechInc_FileNumber MertechInc_DriverName Function 22 CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 4 RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        NATIVE_OPTIMIZATION
/// @Description Allows user to turn off the use of index hints on the native server.
/// Hints are off by default in Microsoft SQL Server and on in Oracle.
///
/// Care should be taken with changing the default, and should only be used
/// if the diagnostics tool of your server indicates performance problems
/// with the type of queries generated.
///
/// @Status      Public
/// @Drivers     SQLFlex, ORAFlex
/// @VersionNote Last Revised: 2011-01-10 By Marcelo
///
/// @Syntax NATIVE_OPTIMIZATION of <Server|Table> Name TO <Default|Use_IndexHint|No_IndexHint>
/// @Param Server       Indicate the scope at Server level
/// @Param Table        Indicate the scope at Table  level
/// @Param Name         Server name or Table name to apply the native optimization settings
///
/// @Usage NATIVE_OPTIMIZATION of Sever "Localhost" to Use_IndexHint
/// @Usage NATIVE_OPTIMIZATION of Table customer    to No_IndexHint
///
#COMMAND NATIVE_OPTIMIZATION "OF" "SERVER""TABLE" R "TO" "DEFAULT""NO_INDEXHINT""USE_INDEXHINT"
    #IFSAME !2 TABLE
        DO_GETFILENUMBER_DRIVERNAME !3
        Move "" to MertechInc_sArg1
    #ELSE
        DO_GETFILENUMBER_DRIVERNAME 0
        Move !3 to MertechInc_sArg1
    #ENDIF

    #IFSAME !5 DEFAULT
        Move 0 to MertechInc_iArg
    #ELSE
        #IFSAME !5 NO_INDEXHINT
            Move 1 to MertechInc_iArg
        #ELSE
            Move 2 to MertechInc_iArg
        #ENDIF
    #ENDIF

    If (MertechInc_DriverName = ORAFLEX or MertechInc_DriverName = SQLFLEX) Begin
        Call_Driver MertechInc_FileNumber MertechInc_DriverName Function CALLDRV_NATIVE_OPTIMIZATION CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank MertechInc_iArg RESULT MertechInc_iRet
    End
    If (MertechInc_iRet = -1) INDICATE ERR True
#ENDCOMMAND

//=============================================================================
/// @Name        SET_ISOLATION_LEVEL
/// @Description Controls the default transaction locking behavior for SELECT statements issued by a connection.
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-17 By Ian Smith
///
/// @Syntax SET_ISOLATION_LEVEL of <Server> to DEFAULT | READ_COMMITTED | READ_UNCOMMITTED | REPEATABLE_READ | SERIALIZABLE
/// @Param Server           Server having the isolation level Set.
/// @Param DEFAULT          (same as READ_COMMITTED for SQL Server)
/// @Param READ_COMMITTED   Specifies that shared locks are held while data is being read to
///                         avoid dirty reads, but the data can be changed before the end of
///                         the transaction, resulting in non-repeatable reads or phantom data.
/// @Param READ_UNCOMMITTED Isolation level 0 locking = No shared locks are issued and no
///                         exclusive locks are honored.  With this option, it is possible to
///                         read uncommitted or dirty data; values in the data can be changed
///                         and rows can appear or disappear in the data set before the end of
///                         the transaction.  Same effect as setting NOLOCK on all tables in
///                         all SELECT statements in a transaction.
/// @Param REPEATABLE_READ  Locks are placed on all data that is used in a query, preventing
///                         other users from updating the data, but new phantom rows can be
///                         insterted into the data set by another user and are included in
///                         later reads in the current transaction.
/// @Param SERIALIZABLE     Places a range lock on the data set, preventing other users from
///                         updating or inserting rows into the data set until the transaction
///                         is complete.  This is the most restrictive of the four isolation
///                         levels. Same effect as setting HOLDLOCK on all tables in all SELECT
///                         statements in a transaction
/// @Example
/// LOGIN "server1" "mertech" "test" "SQL_DRV"
/// SET_ISOLATION_LEVEL of "server1" to READ_COMMITTED
///
#COMMAND SET_ISOLATION_LEVEL "OF" R "TO" "DEFAULT""READ_COMMITTED""READ_UNCOMMITTED""REPEATABLE_READ""SERIALIZABLE""SNAPSHOT_LEVEL"
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_DriverName EQ SQLFLEX or MertechInc_DriverName EQ MYSQLFLEX) Begin
        Move !2 to MertechInc_sArg1

        #IFSAME !4 READ_COMMITTED
            Move 0 to MertechInc_iArg
        #ELSE
            #IFSAME !4 READ_UNCOMMITTED
                Move 1 to MertechInc_iArg
            #ELSE
                #IFSAME !4 REPEATABLE_READ
                    Move 2 to MertechInc_iArg
                #ELSE
                    #IFSAME !4 SERIALIZABLE
                        Move 3 to MertechInc_iArg
                    #ELSE
                        #IFSAME !4 SNAPSHOT_LEVEL
                            Move 4 to MertechInc_iArg
                        #ELSE
                            Move 5 to MertechInc_iArg
                        #ENDIF
                    #ENDIF
                #ENDIF
            #ENDIF
        #ENDIF

        Call_Driver 0 MertechInc_DriverName Function CALLDRV_SET_ISOLATION_LEVEL CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank MertechInc_iArg RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        SET_SESSION_PARAMETER
/// @Description Turns on or off the OEM to ANSI translation
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-17 By Ian Smith
///
/// @Syntax SET_SESSION_PARAMTER OEM_TRANSLATION_STATE | OEM_TO_ANSI to DFFALSE | DFTRUE
/// @Param OEM_TRANSLATION_STATE All Drivers
/// @Param OEM_TO_ANSI           MS SQL only
///
#COMMAND SET_SESSION_PARAMETER "OEM_TRANSLATION_STATE""OEM_TO_ANSI" "TO" R
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        Move !3 to MertechInc_sArg1

        #IFSAME !1 OEM_TO_ANSI
            Move CALLDRV_OLEDB_OEM_TRANSLATION to MertechInc_iArg
        #ELSE
            Move CALLDRV_OEM_TRANSLATION_STATE to MertechInc_iArg
        #ENDIF

        Call_Driver 0 MertechInc_DriverName Function 0 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank MertechInc_iArg RESULT MertechInc_iRet
    End
#ENDCOMMAND

Procedure MertechInc_SET_CUSTOM_OEM_TO_ANSI Global Integer iChar Integer iOem Integer iAnsi
    Move iChar to MertechInc_sArg1
    move (String(iOem) + "," + String(iAnsi)) to MertechInc_sArg2
    Call_Driver 0 MertechInc_DriverName Function CALLDRV_LICENSE_ENVIRONMENT_SET CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_sArg2 CALLDRV_SET_CUSTOM_OEM_TO_ANSI RESULT MertechInc_iRet
    IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
End_Procedure

//=============================================================================
/// @Name        SET_CUSTOM_OEM_TO_ANSI
/// @Description Set custom entry for the OEM and ANSI character translation
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2011/08/01 By Marcelo
///
/// @Syntax SET_CUSTOM_OEM_TO_ANSI CharEntry To OEM OemValue ANSI AnsiValue
/// @Param CharEntry It is the character entry position (0 to 255)
/// @Param OemValue  It is the character number for the Oem character
/// @Param AnsiValue It is the character number for the Ansi character
#COMMAND SET_CUSTOM_OEM_TO_ANSI R "TO" "OEM" R "ANSI" R .
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        Send MertechInc_SET_CUSTOM_OEM_TO_ANSI !1 !4 !6
    End
#ENDCOMMAND

Procedure MertechInc_GET_CUSTOM_OEM_TO_ANSI Global Integer iChar Integer iOem Integer iAnsi
    Move iChar to MertechInc_sArg1
    Move (Repeat(" ", 255)) to MertechInc_sArg2
    Call_Driver 0 MertechInc_DriverName Function CALLDRV_LICENSE_ENVIRONMENT_SET CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_sArg2 CALLDRV_GET_CUSTOM_OEM_TO_ANSI RESULT MertechInc_iRet
    IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
End_Function

//=============================================================================
/// @Name        GET_CUSTOM_OEM_TO_ANSI
/// @Description Get custom entry for the OEM and ANSI character translation for a given character
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2011/08/01 By Marcelo
///
/// @Syntax GET_CUSTOM_OEM_TO_ANSI CharEntry To OEM OemValue ANSI AnsiValue
/// @Param CharEntry It is the character entry position (0 to 255)
/// @Param OemValue  It is a variable to keep the value for the Oem character
/// @Param AnsiValue It is a variable to keep the value for the Ansi character
#COMMAND GET_CUSTOM_OEM_TO_ANSI R "TO" "OEM" R "ANSI" R .
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        Send MertechInc_GET_CUSTOM_OEM_TO_ANSI !1 !4 !6
        [Not Err] Begin
            Move MertechInc_sArg1 to !4
            Move MertechInc_sArg2 to !6
        End
    End
#ENDCOMMAND

//=============================================================================
/// @Name        SET_AUTOMATIC_NUMERIC_DATATYPE_REMAPPING
/// @Description
/// Turns off the automatic numeric data type remapping in SQLFlex.
///
/// Normally when creating a table through restructuring SQLFlex will
/// pick datatypes such as smallint, int, or bigint for smaller numeric
/// types, since they are more efficiently handled by the server.
///
/// Set this to DFFALSE to ensure that the driver always
/// creates the fields as decimal/numeric(x,y).
///
/// @Status      Public
/// @Drivers     SQLFlex
/// @VersionNote Last Revised: 2010-05-10 By Marcelo
///
/// @Syntax SET_AUTOMATIC_NUMERIC_DATATYPE_REMAPPING to DFFALSE | DFTRUE
///
#COMMAND SET_AUTOMATIC_NUMERIC_DATATYPE_REMAPPING "TO" R
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        Move !2 to MertechInc_sArg1
        Call_Driver 0 MertechInc_DriverName Function 0 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank CALLDRV_AUTO_NUMERIC_REMAPPING RESULT MertechInc_iRet
    End
#ENDCOMMAND


//=============================================================================
/// @Name        SET_FORCE_DATE_FORMAT_INIT
/// @Description Forces the date format initialization after a stored
/// procedure/function or trigger execution.
///
/// Data format initialization is off by default, and only needs
/// to be turned on if a trigger or stored procedure will make
/// changes to the default date format used by the session.
///
/// @Status      Public
/// @Drivers     ORAFlex
/// @VersionNote Last Revised: 2010-05-24 By Marcelo
///
/// @Syntax SET_FORCE_DATE_FORMAT_INIT to DFFALSE | DFTRUE
///
#COMMAND SET_FORCE_DATE_FORMAT_INIT "TO" R
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        Move !2 to MertechInc_sArg1
        Call_Driver 0 MertechInc_DriverName Function 0 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank CALLDRV_FORCE_DATE_FORMAT_INIT RESULT MertechInc_iRet
    End
#ENDCOMMAND


//=============================================================================
/// @Name        SET_STATIC_TABLE_OPTIMIZATION
/// @Description
/// Smaller static tables are by default cached by the driver.
/// This macro allows you to turn it off, in case changes are made
/// to the static table outside of Dataflex, or to conserve memory
///
/// @Status      Public
/// @Drivers     SQLFlex
/// @VersionNote Last Revised: 2010-08-17 By Marcelo
///
/// @Syntax SET_STATIC_TABLE_OPTIMIZATION to ENABLED | DISABLED
///
/// @Comment This static table optimization is enabled by default in v11 and beyond
///
#COMMAND SET_STATIC_TABLE_OPTIMIZATION "TO" "ENABLED""DISABLED" .
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        #IFSAME !1 DISABLED
            Move 0 to MertechInc_sArg1
        #ELSE
            Move 1 to MertechInc_sArg1
        #ENDIF
        Call_Driver 0 MertechInc_DriverName Function 0 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank CALLDRV_STATIC_TABLE_OPT RESULT MertechInc_iRet
    End
#ENDCOMMAND


//=============================================================================
/// @Name        GET_MAX_OBJECT_NAME_LENGTH
/// @Description Get the maximum object name length allowed by the logged database.
/// @Status      Public
/// @Drivers     MySQLFlex, ORAFlex, PgFlex and SQLFlex v11.0
/// @VersionNote Last Revised: 2011-05-02 By Marcelo
///
/// @Syntax GET_MAX_OBJECT_NAME_LENGTH to <variable>
///
#COMMAND GET_MAX_OBJECT_NAME_LENGTH "TO" R .
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        Move (Repeat(" ", 10)) to MertechInc_sArg1
        Call_Driver 0 MertechInc_DriverName Function 0 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank CALLDRV_MAX_OBJECT_NAME_LENGTH RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
        Move MertechInc_sArg1 to !2
    End
#ENDCOMMAND


//=============================================================================
/// @Name        SET_SQL_LOCK_TIMEOUT
/// @Description
/// Set the number of milliseconds a statement waits for a lock to be released.
/// If the lock is not released before the timeout ends an error is set.
///
/// Default value is -1, meaning to wait indefinitely for locks.
/// @Status      Public
/// @Drivers     SQLFlex
/// @VersionNote Last Revised: 2009-08-17 By Ian Smith
/// @See SET_SQL_LOCK_TIMEOUT GET_SQL_LOCK_TIMEOUT
///
/// @Syntax SET_SQL_LOCAL_TIMEOUT OF <Servername> TO <IntVar>
/// @Param Servername  Name of the Database server
/// @Param Timeout     Number of milliseconds for timeout
///
///
#COMMAND SET_SQL_LOCK_TIMEOUT "OF" R "TO" R
    DO_GETFILENUMBER_DRIVERNAME 0
    IF MertechInc_DriverName EQ SQLFLEX Begin
        MOVE !2 TO MertechInc_sArg1
        MOVE !4 TO MertechInc_iArg

        Call_Driver 0 MertechInc_DriverName FUNCTION CALLDRV_SET_SQL_LOCK_TIMEOUT CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank MertechInc_iArg RESULT MertechInc_iRet
        IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
    End
#ENDCOMMAND

//=============================================================================
/// @Name        GET_SQL_LOCK_TIMEOUT
/// @Description Get the lock timeout (milliseconds a statement waits
/// for a lock to be released).
/// @Status      Public
/// @Drivers     SQLFlex
/// @VersionNote Last Revised: 2009-08-17 By Ian Smith
/// @See SET_SQL_LOCK_TIMEOUT GET_SQL_LOCK_TIMEOUT
///
/// @Syntax SET_SQL_LOCAL_TIMEOUT OF <Servername> TO <IntVar>
/// @Param Servername  Name of the Database server
/// @Param IntVar      Variable receiving the returned value
///
/// @Comment Default: -1, indicates no time-out period.
///
#COMMAND GET_SQL_LOCK_TIMEOUT "OF" R "TO" R
    DO_GETFILENUMBER_DRIVERNAME 0
    If MertechInc_DriverName EQ SQLFLEX Begin
        Move !2 to MertechInc_sArg1
        Move (Repeat(" ", 10)) to MertechInc_sArg2

        Call_Driver 0 MertechInc_DriverName Function CALLDRV_GET_SQL_LOCK_TIMEOUT CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_sArg2 0 RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
        Move MertechInc_sArg2 to !4
    End
#ENDCOMMAND

//=============================================================================
/// @Name        DO_GET_SQLSERVER_PARAMETERS
/// @Description Retrieves stored procedure parameter values.
/// @Status      Internal
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-18 By Ian Smith
///
/// @Syntax ?? ?? ??
///
#COMMAND DO_GET_SQLSERVER_PARAMETERS
    #IF (!0>1)
        INCREMENT MertechInc_iParamCount
        #IFSAME !2 SQLOUT
            IF (POS("|V",|CS'!1') NE 0 OR POS("|S",|CS'!1') NE 0 OR POS("|F",|CS'!1') NE 0) BEGIN
                Send MertechInc_Set_DecSep     //Check Decimal Seperator and change to '.' if required
                Get MertechInc_DO_GET_SQLSERVER_PARAMETERS MertechInc_iParamCount to !1
                Send MertechInc_Reset_DecSep   //Reset Decimal Seperator if required
            END
            #IF (!0>2)
                DO_GET_SQLSERVER_PARAMETERS !3 !4 !5 !6 !7 !8 !9
            #ENDIF
        #ELSE
            DO_GET_SQLSERVER_PARAMETERS !2 !3 !4 !5 !6 !7 !8 !9
        #ENDIF
    #ENDIF
#ENDCOMMAND // DO_GET_SQLSERVER_PARAMETERS

Function MertechInc_DO_GET_SQLSERVER_PARAMETERS Global Integer iParameter Returns String
    Local String sValue

    Get MertechInc_Pre_Size_String 0 to sValue //Need to check if Call_Driver needs pre sized strings. Until then assume it does
    Call_Driver MertechInc_FileNumber MertechInc_DriverName Function 24 CALLBACK 0 PASSING sValue MertechInc_Blank iParameter RESULT MertechInc_iRet

    Function_Return sValue
End_Function

//=============================================================================
/// @Name        DO_BIND_SQLSERVER_PARAMETERS
/// @Description Binds parameters for stored procedure call
/// @Status      Internal
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-18 By Ian Smith
///
/// @Syntax ?? ?? ??
///
#COMMAND DO_BIND_SQLSERVER_PARAMETERS
    #IFSAME !1 BINDING
    #ELSE
        #IFSAME !2 SQLOUT
            Move "OUTPUT" to MertechInc_sWork
        #ELSE
            Move "INPUT" to MertechInc_sWork
        #ENDIF

        If (POS("|V",|CS'!1') NE 0 or POS("|S",|CS'!1') NE 0 or POS("|F",|CS'!1') NE 0) Begin
            If (POS("|VI",|CS'!1') NE 0 or POS("|SI",|CS'!1') NE 0) Move 6 to MertechInc_iWork
            Else If (POS("|VN",|CS'!1') NE 0 or POS("|SN",|CS'!1') NE 0 or POS("|FN",|CS'!1') NE 0) Move 25 to MertechInc_iWork
                Else If (POS("|VD",|CS'!1') NE 0 or POS("|SD",|CS'!1') NE 0 or POS("|FD",|CS'!1') NE 0) Move 10 to MertechInc_iWork
                    Else If (POS("|VS",|CS'!1') NE 0) Move 255 to MertechInc_iWork
                        Else If (POS("|SS",|CS'!1') NE 0 or POS("|FS",|CS'!1') NE 0) Move 16384 to MertechInc_iWork
            Increment MertechInc_iParamCount
        End
        Else Begin
            Move (LENGTH(!1)) to MertechInc_iWork
        End

        Send MertechInc_DO_BIND_SQLSERVER_PARAMETERS MertechInc_sWork !1 MertechInc_iWork
        #IF (!0>1)
            #IFSAME !2 SQLOUT
                #IF (!0>2)
                    DO_BIND_SQLSERVER_PARAMETERS !3 !4 !5 !6 !7 !8 !9
                #ENDIF
            #ELSE
                DO_BIND_SQLSERVER_PARAMETERS !2 !3 !4 !5 !6 !7 !8 !9
            #ENDIF
        #ENDIF
    #ENDIF
#ENDCOMMAND // DO_BIND_SQLSERVER_PARAMETERS

Procedure MertechInc_DO_BIND_SQLSERVER_PARAMETERS Global String sDirection String sParameter Integer iSize
    Call_Driver 0 SQLFLEX Function 23 CALLBACK 0 PASSING sDirection sParameter iSize RESULT MertechInc_iRet
End_Procedure

//=============================================================================
/// @Name        DO_CHECK_BINDING
/// @Description Sets MertechInc_bThereIsBinding True if any of the parameters is the keyword BINDING
/// @Status      Internal
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-18 By Ian Smith
///
/// @Syntax ?? ?? ??
///
#COMMAND DO_CHECK_BINDING
    #IFSAME !1 BINDING
        INDICATE MertechInc_bThereIsBinding True
    #ELSE
        #IF (!0>1)
            DO_CHECK_BINDING !2 !3 !4 !5 !6 !7 !8 !9
        #ENDIF
    #ENDIF
#ENDCOMMAND

//=============================================================================
/// @Name        DO_FETCH_FIRST_ROW
/// @Description Recursive - drops first parameter until the first parameter is BINDING and
/// @Description then calls SQL_FETCH_NEXT_ROW passing remaining parameters
/// @Status      Internal
/// @Drivers     SQLFlex
/// @VersionNote Last Revised: 2009-08-18 By Ian Smith
///
/// @Syntax ?? ?? ??
///
#COMMAND DO_FETCH_FIRST_ROW
    #IFSAME !1 BINDING
        SQL_FETCH_NEXT_ROW INTO !2 !3 !4 !5 !6 !7 !8 !9
    #ELSE
        #IF (!0>1)
            DO_FETCH_FIRST_ROW !2 !3 !4 !5 !6 !7 !8 !9
        #ENDIF
    #ENDIF
#ENDCOMMAND

//=============================================================================
/// @Name        CALL_SQLFLEX7_PROCEDURE
/// @Description Executes a MS_SQL server stored procedure (v7 or later)
/// @Status      Internal
/// @Drivers     SQLFlex
/// @VersionNote Last Revised: 2009-08-18 By Ian Smith
///
/// @Syntax CALL_SQLFLEX7_PROCEDURE <ProcName> {PASSING <Arg1> [SQLOUT] {. <Argn> [SQLOUT]}
/// @Syntax CALL_SQLFLEX7_PROCEDURE <ProcName> {BINDING <Var1> {. <Varn>}
/// @Param ProcName    Full name of procedure
/// @Param Arg1..Argn  Arguments passed to the procedure
/// @Param Var1..Varn  Program Variables
///
#COMMAND CALL_SQLFLEX7_PROCEDURE R "PASSING""BINDING"""
    INDICATE MertechInc_bThereIsBinding False
    DO_CHECK_BINDING !3 !4 !5 !6 !7 !8 !9

    MOVE 0 TO MertechInc_iParamCount
    INDICATE ERR FALSE
    SQL_SET_STMT to "{? = CALL "
    SQL_APPEND_STMT TO !1
    SQL_APPEND_STMT TO " "
    #IF (!0>2)
        DDO_PASS_ARGUMENTS !2 !3 !4 !5 !6 !7 !8 !9
        IF (MertechInc_iParamCount > 0) SQL_APPEND_STMT TO ")"
    #ENDIF
    SQL_APPEND_STMT TO  " }"

    MOVE 0 TO MertechInc_iParamCount
    SQL_PREPARE_STMT
    DDO_BIND_PARAMETERS MertechInc_iWork SQLOUT !2 !3 !4 !5 !6 !7 !8 !9

    SQL_EXECUTE_STMT
    If ( MertechInc_iParamCount GT 0 ) Begin
        Move 0 to MertechInc_iParamCount
        [not MertechInc_bThereIsBinding] DO_GET_SQLSERVER_PARAMETERS !3 !4 !5 !6 !7 !8 !9
    End

    DO_FETCH_FIRST_ROW !3 !4 !5 !6 !7 !8 !9
#ENDCOMMAND // CALL_SQLFLEX7_PROCEDURE

//=============================================================================
/// @Name        CALL_REEXEC_SQLFLEX7_PROCEDURE
/// @Description Unknown - Not in help - Not call by any other macros
/// @Status      Internal
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-18 By Ian Smith
///
/// @Syntax ?? ?? ??
///
#COMMAND CALL_REEXEC_SQLFLEX7_PROCEDURE R "PASSING""BINDING"""
    SQL_SET_STMT TO ""
    MOVE 0 TO MertechInc_iParamCount
    DDO_BIND_PARAMETERS MertechInc_iWork SQLOUT !2 !3 !4 !5 !6 !7 !8 !9

    SQL_EXECUTE_STMT
    If ( MertechInc_iParamCount GT 0 ) BEGIN
        MOVE 0 TO MertechInc_iParamCount
        [not MertechInc_bThereIsBinding] DO_GET_SQLSERVER_PARAMETERS !3 !4 !5 !6 !7 !8 !9
    END

    DO_FETCH_FIRST_ROW !3 !4 !5 !6 !7 !8 !9
#ENDCOMMAND // CALL_REEXEC_SQLFLEX7_PROCEDURE

//=============================================================================
/// @Name        CALL_SQLFLEX2_PROCEDURE
/// @Description Executes a MS_SQL server stored procedure (pre v7)
/// @Status      Internal
/// @Drivers     SQLFlex
/// @VersionNote Last Revised: 2009-08-18 By Ian Smith
///
/// @Syntax CALL_SQLFLEX2_PROCEDURE <ProcName> {PASSING <Arg1> [SQLOUT] {. <Argn> [SQLOUT]}
/// @Syntax CALL_SQLFLEX2_PROCEDURE <ProcName> {BINDING <Var1> {. <Varn>}
/// @Param ProcName    Full name of procedure
/// @Param Arg1..Argn  Arguments passed to the procedure
/// @Param Var1..Varn  Program Variables
///
#COMMAND CALL_SQLFLEX2_PROCEDURE R "PASSING""BINDING"""
    MOVE 0 TO MertechInc_iParamCount
    Move SQLFLEX TO MertechInc_DriverName
    INDICATE ERR FALSE
    // INITIALIZE THE CALL
    #IFSAME !2 BINDING
        SQL_SET_STMT TO !1
        Call_Driver MertechInc_FileNumber MertechInc_DriverName Function 22 CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 5 RESULT MertechInc_iRet
        SQL_FETCH_NEXT_ROW INTO !3 !4 !5 !6 !7 !8 !9
    #ELSE
        MOVE !1 TO MertechInc_sArg1
        Call_Driver MertechInc_FileNumber MertechInc_DriverName FUNCTION 25 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 0 RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True

        #IF (!0=9) // SEND THE ARGUMENTS
            [ not ERR ] DO_BIND_SQLSERVER_PARAMETERS (!3) (!4) (!5) (!6) (!7) (!8) (!9)
        #ENDIF
        #IF (!0=8) // SEND THE ARGUMENTS
            [ not ERR ] DO_BIND_SQLSERVER_PARAMETERS (!3) (!4) (!5) (!6) (!7) (!8)
        #ENDIF
        #IF (!0=7) // SEND THE ARGUMENTS
            [ not ERR ] DO_BIND_SQLSERVER_PARAMETERS (!3) (!4) (!5) (!6) (!7)
        #ENDIF
        #IF (!0=6) // SEND THE ARGUMENTS
            [ not ERR ] DO_BIND_SQLSERVER_PARAMETERS (!3) (!4) (!5) (!6)
        #ENDIF
        #IF (!0=5) // SEND THE ARGUMENTS
            [ not ERR ] DO_BIND_SQLSERVER_PARAMETERS (!3) (!4) (!5)
        #ENDIF
        #IF (!0=4) // SEND THE ARGUMENTS
            [ not ERR ] DO_BIND_SQLSERVER_PARAMETERS (!3) (!4)
        #ENDIF
        #IF (!0=3) // SEND THE ARGUMENTS
            [ not ERR ] DO_BIND_SQLSERVER_PARAMETERS (!3)
        #ENDIF
        // EXECUTE THE CALL
        [ NOT ERR ] BEGIN
            Call_Driver MertechInc_FileNumber MertechInc_DriverName Function 26 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 0 RESULT MertechInc_iRet
            IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
        END
        // GET THE VALUES BACK
        [ NOT ERR ] BEGIN
            If ( MertechInc_iParamCount GT 0 ) BEGIN
                MOVE 0 TO MertechInc_iParamCount
                DO_GET_SQLSERVER_PARAMETERS !3 !4 !5 !6 !7 !8 !9
            END
        END
    #ENDIF
#ENDCOMMAND // CALL_SQLFLEX2_PROCEDURE

//=============================================================================
/// @Name        CALL_SQLSERVER_PROCEDURE
/// @Description
/// Calls a stored procedure on MS SQL Server. The return value is stored
/// in the argument defined after SQLOUT. Error strings can be retrieved
/// using the SQL_ERROR_MESSAGE command.
///
/// @Status      Public
/// @Drivers     SQLFlex
/// @VersionNote Last Revised: 2009-08-18 By Ian Smith
/// @See CALL_SQLSERVER_PROCEDURE END_CALL_PROCEDURE
///
/// @Syntax CALL_SQLSERVER_PROCEDURE <ProcName> {PASSING <Arg1> [SQLOUT] {. <Argn> [SQLOUT]}
/// @Syntax CALL_SQLSERVER_PROCEDURE <ProcName> {BINDING <Var1> {. <Varn>}
/// @Param ProcName    Full name of procedure
/// @Param Arg1..Argn  Arguments passed to the procedure
/// @Param Var1..Varn  Program Variables
///
/// @Usage CALL_SQLSERVER_PROCEDURE "SET_CUST_CREDLIM" passing nVar1 sVar1 nVar2 SqlOut
/// @Usage CALL_SQLSERVER_PROCEDURE "SEARCH_CUST_CREDLIM" passing nVar1 SqlOut nVar2 SqlOut nVar3 SqlOut nVar4
/// @Usage CALL_SQLSERVER_PROCEDURE "LIST_SALESP" binding ID NAME
///
#COMMAND CALL_SQLSERVER_PROCEDURE R "PASSING""BINDING"""
//    SQLFlex_MAJOR_REVISION MertechInc_sWork
//    If MertechInc_sWork GE 7 Begin
        CALL_SQLFLEX7_PROCEDURE !1 !2 !3 !4 !5 !6 !7 !8 !9
//    END
//    ELSE BEGIN
//        CALL_SQLFLEX2_PROCEDURE !1 !2 !3 !4 !5 !6 !7 !8 !9
//    END
#ENDCOMMAND // CALL_SQLSERVER_PROCEDURE

#Replace CALL_SQLSERVER_STORED_PROCEDURE CALL_SQLSERVER_PROCEDURE

//=============================================================================
/// @Name        END_CALL_PROCEDURE
/// @Description Closes open cursors created by the CALL_SQLSERVER_STORED_PROCEDURE
/// @Status      Public
/// @Drivers     SQLFlex
/// @VersionNote Last Revised: 2009-08-18 By Ian Smith
/// @See CALL_SQLSERVER_PROCEDURE END_CALL_PROCEDURE
///
/// @Syntax END_CALL_PROCEDURE
///
#COMMAND END_CALL_PROCEDURE .
    CALL_DRIVER 0 SQLFLEX FUNCTION 26 CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 0 RESULT MertechInc_iRet
#ENDCOMMAND

//=============================================================================
/// @Name        GET_PROCEDURE_RETURN
/// @Description Gets stored procedure return value
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-12 By Ian Smith
///
/// @Syntax GET_PROCEDURE_RETURN TO <Var>
/// @Param TO  Constant
/// @Param Var Variable to hole returned value
///
#COMMAND GET_PROCEDURE_RETURN "TO" R .
    CALL_DRIVER 0 SQLFLEX FUNCTION 27 CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 0 RESULT MertechInc_iRet
    Move MertechInc_iRet TO !2
#ENDCOMMAND

//=============================================================================
/// @Name        SET_MIRROR_SERVER
/// @Description Sets the name of the mirrored server and database, for use
/// with SQL Server Mirroring
/// @Status      Public
/// @Drivers     SQLFlex v9.2 and above
/// @DBMS SQL Server 2005 and above
/// @VersionNote Last Revised: 2009-08-18 By Ian Smith
/// @See SET_MIRROR_SERVER GET_MIRROR_SERVER
///
/// @Syntax SET_MIRROR_SERVER TO [sMirrorServer] [sMirrorDatabase]
/// @Param sMirrorServer   mirrored server name
/// @Param sMirrorDatabase mirrored database name
///
/// @Usage SET_MIRROR_SERVER to "FailoverPartner" "AdventureWorks"
/// @Example
/// use mertech.inc
/// string p1 p2
/// Load_Driver "SQL_DRV"
/// SET_MIRROR_SERVER to "hostName\mirrorServer" "MainServer"
/// If (Err) showln "Error setting failover Server"
/// login "MACHINE\MAIN" "user" "password" "sql_drv"
///
#COMMAND SET_MIRROR_SERVER "TO" R R .
    DO_GETFILENUMBER_DRIVERNAME 0

    IF (MertechInc_DriverName EQ SQLFlex) Begin
        MOVE !2 TO MertechInc_sArg1
        Move !3 to MertechInc_sArg2
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_MIRROR_SERVER CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_sArg2 0 RESULT MertechInc_iRet
    End
    IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
#ENDCOMMAND

//=============================================================================
/// @Name        GET_MIRROR_SERVER
/// @Description Gets the name of the mirrored server and database, for use
/// with SQL Server Mirroring
/// @Status      Public
/// @Drivers     SQLFlex v9.2 and above
/// @VersionNote Last Revised: 2009-08-18 By Ian Smith
/// @See SET_MIRROR_SERVER GET_MIRROR_SERVER
///
/// @Syntax GET_MIRROR_SERVER TO [sMirrorServer] [sMirrorDatabase]
/// @Param sMirrorServer   mirrored server name
/// @Param sMirrorDatabase mirrored database name
///
#COMMAND GET_MIRROR_SERVER "TO" R R .
    DO_GETFILENUMBER_DRIVERNAME 0

    IF (MertechInc_DriverName EQ SQLFlex) Begin
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_MIRROR_SERVER CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_sArg2 1 RESULT MertechInc_iRet
        MOVE MertechInc_sArg1 TO !2
        Move MertechInc_sArg2 to !3
    End
    IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
#ENDCOMMAND

//=============================================================================
/// @Name        COPY_DATA
/// @Description
/// COPY_DATA can be used to copy data from an SQL
/// table to a DAT file and vice versa.
///
/// Flex2SQL also has options to copy data from a DAT file to an SQL table
/// and vice versa, but the COPY_DATA command provides improved performance
/// by eliminating the overhead required by the interaction between the Flex2SQL
/// application and the DataFlex runtime.
///
/// COPY_DATA opens the source and destination files, copies the data,
/// and then closes the files. When the source file is an SQL table,
/// a command line argument can be used to restrict the table rows that are
/// copied to the DAT file, in the form of an SQL WHERE clause.
///
/// The COPY_DATA macro is based on the regular DataFlex command Copy_DB.
/// Since COPY_DATA requires no user interaction, trace messages are provided
/// to monitor the copy process and to display any error messages.
///
/// The call back function must be declared as
/// Function Callback  String sText  Integer iLogicalID  Returns Integer
/// If a constraint is required and a call back not required code the call back function as 0 (zero)
///
/// See the example for the callback messages defined.
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-18 By Ian Smith
///
/// @Syntax COPY_DATA <src_table> to <dest_table> [CALLBACK cb_obj] [Constrain constr]
/// @Param src_table  Source table to use
/// @Param dest_table Destination table
/// @Param cb_obj     Optional object with call back function
/// @Param constr     Optional SQL constraint to use when copying
///
/// @Example
/// // The following code copies data from a table named DIARY into a DAT file named DIARY.
/// // Only the rows containing JobCode = 02-78CC are copied.
///
/// Copy_Data "sql_drv:diary" To "diary" Callback 0 Constrain "JobCode = '02-78CC'"
///
/// // The following code copies data from a table named CREW into a DAT file named CREW2.
/// // Only the rows containing JobCode = 02-78CC are copied.
/// // This code has a callback object that interacts with the driver during
/// // the migration.
///
/// Integer giCallBackObj
/// Object CallBackObj Is A Array
/// Move Self To giCallBackObj
/// Function Callback String sText Integer iLogicalID Returns Integer
///     If (iLogicalID = DF_MESSAGE_ERROR) Begin
///         ::
///         <handle Error Message>
///         ::
///         // Tell operation to Stop
///         // Function_Return DFTRUE
///     End
///     Else If (iLogicalID >= DF_MESSAGE_PROGRESS_STATUS) Begin
///     ::
///     <Handle Data Migration Progress>
///     ::
///     // Tell operation to Continue
///     // Function_Return DFFALSE
///     End
///     Function_Return DFFALSE
/// End_Function
/// End_Object
///
///  Copy_Data "sql_drv:crew" To "crew2" Callback (CallBackObj(Self)) Constrain "JobCode = '02-78CC'"
///
/// // The following code copies all the data from a DAT file named
/// // TIMECARD to an SQL table named TIMECARD.
///
/// Copy_Data "timecard" To "sql_drv:timecard" Callback 0
///
/// // The following code copies some records from an SQL table to a DAT file.
///
/// use mertech.inc
///
/// //
/// // Simple Object with a Callback function
/// //
/// // Call back messages are:
/// // DF_MESSAGE_PROGRESS_TITLE    Sent when SQLFlex starts the process.
/// // DF_MESSAGE_HEADING_1         Sent when SQLFlex is about to copy the
/// //                              source data.
/// // DF_MESSAGE_ERROR             Sent when an error occurs.
/// // DF_MESSAGE_PROGRESS_STATUS   Sent each time an additional 10% of the data is copied.
/// //                              The message format is
/// //                              "<number of records saved>,<total number of records>"
///
/// Integer giCallBackObj
/// Object CallBackObj Is A Array
/// Move current_object To giCallBackObj
/// Function Callback String sText Integer iLogicalID Returns Integer
///     Integer iWorking ret# herr# liPos liLen liCount liTotal liPercent
///     String lsValue
///     if (iLogicalID = DF_MESSAGE_PROGRESS_TITLE) Begin
///         // Message sent when SQLFlex is starting the Copy Data process
///         showln "Title " sText
///         showln
///     End
///     else if (iLogicalID = DF_MESSAGE_HEADING_1) Begin
///         // Message sent when SQLFlex is about to copy the data from source
///         // to destination and when the operation is done
///         showln "Sub-Title " sText
///     End
///     else If (iLogicalID = DF_MESSAGE_ERROR) Begin
///         // This message is sent when there is an error during the migration
///         showln "Error " sText
///         function_return dftrue
///        // Function_return dftrue means you want the migration to stop
///     End
///     Else If (iLogicalID >= DF_MESSAGE_PROGRESS_STATUS) Begin
///         // This message is sent each time another 10% of the data is copied
///         showln "Progress " sText
///     End
///     Function_Return dffalse
///     End_Function
/// End_Object
/// login "server" "user" "password" "sql_drv"
/// open "customer" as customer
/// zerofile customer
/// //
/// // All records in Customer table that contain STATE = 'FL', will be copied
/// // to Customer.DAT file
/// //
/// copy_data "sql_drv:customer" to "customer" callback giCallBackObj constrain "STATE = 'FL'"
///
/// open "salesp.int" as salesp
/// zerofile salesp
/// close salesp
/// //
/// // All records from Salesp.DAT will be copied to Salesp table
/// //
/// copy_data "salesp" to "sql_drv:salesp" callback giCallBackObj

#COMMAND COPY_DATA R "TO" R
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        Move (!1 + "||" + !3) to MertechInc_sArg1
        #IF !0>3
            #CHECK !4 "CALLBACK"
            Move !5 to MertechInc_iCallBack
            #IF !0>5
                #CHECK !6 "CONSTRAIN"
                Move !7 to MertechInc_sArg2
            #ELSE
                Move "" to MertechInc_sArg2
            #ENDIF
        #ELSE
            Move 0 to MertechInc_iCallBack
        #ENDIF
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_COPY_DATA CALLBACK MertechInc_iCallBack PASSING MertechInc_sArg1 MertechInc_sArg2 0 RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        ORAFlex_REVISION
/// @Description Retrieves the ORAFlex version currently in use.
/// @Status      Public
/// @Drivers     ORAFlex
/// @VersionNote Last Revised: 2009-08-18 By Ian Smith
///
/// @Syntax ORAFlex_REVISION <Var>
/// @Param Var Variable to receive the attribute
///
#COMMAND ORAFlex_REVISION #CRUG .
    Move (Repeat(" ",255)) to !1
    Call_Driver 0 ORAFlex Function 0 CALLBACK 0 PASSING MertechInc_Blank !1 0 RESULT MertechInc_iRet
    If MertechInc_iRet EQ -1 INDICATE ERR True
#ENDCOMMAND

//=============================================================================
/// @Name        KEEP_FILES_OPEN
/// @Description Keep the files, currently in use, open after the server is logged out.
///
/// Sometimes an application needs to logon to the same server with a different user id.
/// When logging out, however, the drivers automatically close all opened files.
/// The overhead of opening these files should be avoided if the user will work
/// with the same files that were closed. KEEP_FILES_OPEN keeps all files opened
/// after a user logs out from the server.
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-18 By Ian Smith
///
/// @Syntax KEEP_FILES_OPEN OF <ServerName>
/// @Param ServerName  Name of the Server whose files will be kept open.
///
#COMMAND KEEP_FILES_OPEN "OF" R .
    #IFDEF MertechInc_Obsolete_Code
        DO_GETFILENUMBER_DRIVERNAME 0
        If (MertechInc_FileNumber <> -1) Begin
            Move !2 to MertechInc_sArg1
            If (MertechInc_DriverName EQ ORAFlex);
                Call_Driver 0 MertechInc_DriverName Function 25 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 0 RESULT MertechInc_iRet
            Else ;
                Call_Driver 0 MertechInc_DriverName Function 28 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 0 RESULT MertechInc_iRet
            If MertechInc_iRet EQ -1 INDICATE ERR True
        End
    #ELSE
        MertechInc_Error_Obsolete_Code
    #ENDIF
#ENDCOMMAND

#REPLACE DONT_CLOSE_FILES KEEP_FILES_OPEN

//=============================================================================
/// @Name        SET_MAX_OPEN_CURSORS
/// @Description Set the maximum number of cursors you want the driver to use.
///
/// The driver will recycle the least used cursors if this limit is hit.
/// The trade off is between increased resources on the server and re-repreparing
/// of cursors.
///
/// For a program that keeps 40+ files opened at the same time, 255 is a good
/// number for the open cursors parameter. For programs that open less than 40 files,
/// any number between 100-255 is sufficient. These numbers can be changed
/// based on available server resources.
///
/// On Oracle this value should not exceed the value of open_cursors in init.ora
///
/// Note: Only change this setting if you are having performance issues
/// and the server is indicating you are using up too many cursors or too much memory.
/// GET_OPENED_CURSORS can be used to check the number of cursors the server has opened.
/// If this number is hitting the limit, it is worth increasing the number,
/// as long as the server has enough resources.
///
/// @Status      Public
/// @Drivers     SQLFlex, ORAFlex, MySQLFlex & PgFlex
/// @VersionNote Last Revised: 2009-08-18 By Ian Smith
/// @See         SET_MAX_OPEN_CURSORS GET_MAX_OPEN_CURSORS GET_OPENED_CURSORS
///
/// @Syntax SET_MAX_OPEN_CURSORS OF <servername> TO <Num>
/// @Param servername  Server to set max cursor for
/// @Param Num         Maximum number of cursor to open (use) before reuse starts
///
#COMMAND SET_MAX_OPEN_CURSORS "OF" R "TO" R .
    DO_GETFILENUMBER_DRIVERNAME 0

    MOVE !2 TO MertechInc_sArg1
    Move "0"  to MertechInc_sArg2
    If (MertechInc_DriverName EQ ORAFlex or MertechInc_DriverName EQ MySQLFlex or MertechInc_DriverName EQ PgFlex)Begin
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_SQL_MAX_CURSORS CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_sArg2 !4 RESULT MertechInc_iRet
    End
    Else If MertechInc_DriverName EQ SQLFlex Begin
        Call_Driver 0 SQLFlex Function CALLDRV_SQLFLEX_MAX_CURSORS CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_sArg2 !4 RESULT MertechInc_iRet
    End
    IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
#ENDCOMMAND

//=============================================================================
/// @Name        GET_MAX_OPEN_CURSORS
/// @Description Get the maximum number of cursors the driver will use.
/// @Status      Public
/// @Drivers     SQLFlex, ORAFlex, MySQLFlex & PgFlex
/// @VersionNote Last Revised: 2009-08-18 By Ian Smith
/// @See         SET_MAX_OPEN_CURSORS GET_MAX_OPEN_CURSORS GET_OPENED_CURSORS
///
/// @Syntax GET_MAX_OPEN_CURSORS OF <servername> TO <Var>
/// @Param servername  Server to set max cursor for
/// @Param Var         Variable to hold retrieved value
///
#COMMAND GET_MAX_OPEN_CURSORS "OF" R "TO" RC .
    DO_GETFILENUMBER_DRIVERNAME 0

    MOVE !2 TO MertechInc_sArg1
    Move "1" to MertechInc_sArg2
    If (MertechInc_DriverName EQ ORAFlex or MertechInc_DriverName EQ MySQLFlex or MertechInc_DriverName EQ PgFlex) Begin
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_SQL_MAX_CURSORS CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_sArg2 0 RESULT MertechInc_iRet
    End
    Else If MertechInc_DriverName EQ SQLFlex Begin
        Call_Driver 0 SQLFlex Function CALLDRV_SQLFLEX_MAX_CURSORS CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_sArg2 0 RESULT MertechInc_iRet
    End
    If MertechInc_iRet EQ -1 INDICATE ERR True
    ELSE MOVE MertechInc_iRet TO !4
#ENDCOMMAND

//=============================================================================
/// @Name        GET_OPENED_CURSORS
/// @Description Get the number of opened cursors.
/// @Status      Public
/// @Drivers     SQLFlex, ORAFlex, MySQLFlex & PgFlex
/// @VersionNote Last Revised: 2009-08-18 By Ian Smith
/// @See         SET_MAX_OPEN_CURSORS GET_MAX_OPEN_CURSORS GET_OPENED_CURSORS
///
/// @Syntax GET_MAX_OPEN_CURSORS OF <servername> TO <Var>
/// @Param servername  Server to set max cursor for
/// @Param Var         Variable to hold retrieved value
///
#COMMAND GET_OPENED_CURSORS "OF" R "TO" RC .
    DO_GETFILENUMBER_DRIVERNAME 0

    MOVE !2 TO MertechInc_sArg1
    Move "2" to MertechInc_sArg2
    If (MertechInc_DriverName EQ ORAFlex or MertechInc_DriverName EQ MySQLFlex or MertechInc_DriverName EQ PgFlex) Begin
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_SQL_MAX_CURSORS CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_sArg2 0 RESULT MertechInc_iRet
    End
    Else If MertechInc_DriverName EQ SQLFlex Begin
        Call_Driver 0 SQLFlex Function CALLDRV_SQLFLEX_MAX_CURSORS CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_sArg2 0 RESULT MertechInc_iRet
    End
    If MertechInc_iRet EQ -1 INDICATE ERR True
    ELSE MOVE MertechInc_iRet TO !4
#ENDCOMMAND

//=============================================================================
/// @Name        ACTIVATE_TIME_STAMP
/// @Description Activates the time stamp for date columns of files of the
/// specified server.
///
/// Please see the example below for more information
///
/// @Status      Public
/// @Drivers     OraFlex
/// @VersionNote Last Revised: 2009-09-19 By Ian Smith
///
/// @Syntax ACTIVATE_TIME_STAMP of <ServerName> to ON|OFF
/// @Param ServerName Name of te server to activate Time Stamp on
///
/// @Usage ACTIVATE_TIME_STAMP of "MYSERVER" TO ON
///
/// @Example
/// // Example 1:
///
/// ACTIVATE_TIME_STAMP of "MYSERVER" TO ON
/// open ORDERHEA
/// clear ORDERHEA
///
/// // Where 30 is the FileNumber and 3 is the FieldNumber
/// SET_ATTRIBUTE DF_FIELD_TIME_ON of 30 3 TO dftrue
/// Showln "Here is a date from the date column in the ORDERHEA table (with time stamp):"
/// Find gt ORDERHEA by Index.3
/// [found] showln ORDERHEA.ORDER_DATE
/// close ORDERHEA
///
/// // In order to perform this command the following steps need to be taken.
///
/// // Migrate your table without making any changes to the file structure.
/// Once the table is created, change the field type from Date to String
/// in the .FD file.
///
/// Example 2:
///
/// #REPLACE FILE.START_TIME | FD60,3  with
/// #REPLACE FILE.START_TIME | FS60,3
///
/// Turn on the DF_TIME_ON attribute for the START_TIME field.
///
/// Set_Attribute DF_FIELD_TIME_ON of FileNo | FileName FieldNo to DFTRUE | DFFALSE
///
/// // Compile the program with this new .FD.
/// // Run your application.

#COMMAND ACTIVATE_TIME_STAMP "OF" R "TO" "ON""OFF"  .
    DO_GETFILENUMBER_DRIVERNAME 0
    If MertechInc_DriverName EQ ORAFlex Begin
        #IFSAME !4 ON
            Move 1 to MertechInc_iArg
        #ELSE
            Move 0 to MertechInc_iArg
        #ENDIF
        Move !2 to MertechInc_sArg1
        Call_Driver 0 MertechInc_DriverName Function 27 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank MertechInc_iArg RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        CALL_ORACLE_STORED_FUNCTION
/// @Description
/// Executes a function-call that is stored in the Oracle database.
///
/// CALL_ORACLE_STORED_FUNCTION calls a stored function in the Oracle database.
///
/// With this command it is also possible to pass arguments to this function.
/// Returned values of the function are passed back in VAR_RET. The indicator ERR
/// will be set to a nonzero value if an error occurs.
///
/// @Status      Public
/// @Drivers     ORAFLex
/// @VersionNote Last Revised: 2009-08-18 By Ian Smith
///
/// @Syntax CALL_ORACLE_STORED_FUNCTION <FuncName> RETURNS <Var_Ret> {PASSING <Arg1> {. <Argn>}}
/// @Param FuncName   Full name of the function.
/// @Param Var_Ret    Variable used to hold the return value of the function.
/// @Param Arg1.Argn  Arguments passed to the function.
/// @Example
/// #INCLUDE MERTECH.INC
///
/// /IMGCURSOR
///
/// CREATE OR REPLACE FUNCTION fEXEC_CURSOR
/// RETURN NUMBER
/// IS
/// nGTotal CUSTOMER.CREDIT_LIMIT%TYPE;
/// begin
///     nGTotal := 0;
///     DECLARE
///         CURSOR uCUSTOMER IS
///             SELECT RECNUM, STATE, CREDIT_LIMIT FROM CUSTOMER;
///     BEGIN
///         FOR x IN uCUSTOMER LOOP
///             IF x.STATE='CA' THEN
///             nGTotal := (nGtotal + x.CREDIT_LIMIT);
///             END IF;
///         END LOOP;
///     END;
///     return nGTotal;
/// exception
///     when others then
///         null;
/// end;
///
/// /*
///
/// LOGIN "server" "user" password" "ORA_DRV"
///
/// procedure sCreate_Function
///     local string sline
///     direct_input channel 9 image IMGCURSOR
///     SQL_SET_STMT to ""
///     READLN channel 9 sline
///     While [ NOT SEQEOF]
///         SQL_APPEND_STMT to sline
///         SQL_APPEND_STMT to (character(10))
///         READLN channel 9 sline
///     Loop
///     close_input channel 9
///     SQL_PREPARE_STMT
///     SQL_EXECUTE_STMT
/// end_procedure
///
/// procedure sCall_Function
///     local NUMBER nTotal
///     MOVE 0 TO nTotal
///     CALL_ORACLE_STORED_FUNCTION "fEXEC_CURSOR" RETURNS nTotal
///     SHOWLN "TOTAL: " nTotal
///     INKEY STRLEN
/// end_procedure
///
/// procedure sDrop_Function
///     SQL_SET_STMT to "DROP FUNCTION fEXEC_CURSOR"
///     SQL_PREPARE_STMT
///     SQL_EXECUTE_STMT
/// end_procedure
///
/// send sCreate_Function
/// send sCall_Function
/// send sDrop_Function

#COMMAND CALL_ORACLE_STORED_FUNCTION R "RETURNS" R "PASSING"""
    MOVE 0 TO MertechInc_iParamCount
    INDICATE ERR FALSE
    SQL_SET_STMT TO "BEGIN "
    SQL_APPEND_STMT TO ":PAR_RET := "
    SQL_APPEND_STMT TO !1
    SQL_APPEND_STMT TO "( "
    #IF (!0>4)
        DO_PASS_ARGUMENTS !5 !6 !7 !8 !9
    #ENDIF
    SQL_APPEND_STMT TO  " ); END;"
    SQL_PREPARE_STMT
    DO_BIND_PAR_RET !3
    #IF (!0>4)
        [ NOT ERR ] BEGIN
            IF MertechInc_iParamCount GT 0 BEGIN
                MOVE 0 TO MertechInc_iParamCount
                DO_BIND_PARAMETERS !5 !6 !7 !8 !9 // Bind the other arguments
            END
        END
    #ENDIF
    SQL_EXECUTE_STMT
    [ NOT ERR ] BEGIN
        MOVE 0 TO MertechInc_iParamCount // Getting returned value
        DO_GET_BIND_PARAMETERS !3
        #IF (!0>4)
            DO_GET_BIND_PARAMETERS !5 !6 !7 !8 !9 // Bind the other arguments
        #ENDIF
    END
#ENDCOMMAND

//=============================================================================
/// @Name        CALL_PGSQL_STORED_FUNCTION
/// @Description Call a PostgreSQL stored function that returns a value.
/// @Status      Public
/// @Drivers     PgFlex
/// @VersionNote Last Revised: 2009-08-18 By Ian Smith
///
/// @Syntax CALL_PGSQL_STORED_FUNCTION <FuncName> RETURNS <Var_Ret> {PASSING <Arg1> {. <Argn>}}
/// @Param FuncName   Full name of the function.
/// @Param Var_Ret    Variable used to hold the return value of the function.
/// @Param Arg1.Argn  Arguments passed to the function.
///
/// @Usage Call_Pgsql_Stored_Function "public.dup_function" RETURNS lsRet PASSING liAttr1 liAttr2 lsAttr3
/// @Usage Call_Pgsql_Stored_Function "public.get_add" RETURNS iRet PASSING 1 2
/// @Usage Call_Pgsql_Stored_Function "public.get_current_date" RETURNS ldAttr4
///
#COMMAND CALL_PGSQL_STORED_FUNCTION R "RETURNS" R "PASSING"""
    MOVE 0 TO MertechInc_iParamCount
    INDICATE ERR FALSE
    SQL_SET_STMT TO !1
    SQL_APPEND_STMT TO "("
    #IF (!0>4)
        DO_PASS_ARGUMENTS !5 !6 !7 !8 !9
    #ENDIF
    SQL_APPEND_STMT TO  ")"
    SQL_PREPARE_STMT

    // Indicate that a stored function will be executed - Query = 0, Procedure = 1, Function = 2
    Call_Driver 0 MertechInc_DriverName Function CALLDRV_EMBEDDED_SQL_TYPE CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 2 RESULT MertechInc_iRet
    #IF (!0>4)
        [ NOT ERR ] BEGIN
            IF MertechInc_iParamCount GT 0 BEGIN
                MOVE 0 TO MertechInc_iParamCount
                DO_BIND_PARAMETERS !5 !6 !7 !8 !9 // Bind the other arguments
            END
        END
    #ENDIF
    SQL_EXECUTE_STMT
    [ NOT ERR ] BEGIN
        MOVE 0 TO MertechInc_iParamCount // Getting returned value
        DO_GET_BIND_PARAMETERS !3
        #IF (!0>4)
            DO_GET_BIND_PARAMETERS !5 !6 !7 !8 !9 // Bind the other arguments
        #ENDIF
    END
#ENDCOMMAND

//=============================================================================
/// @Name        MERTECH_LANGUAGE_SUPPORT
/// @Description Internal
/// @Status      Public
/// @Drivers     ORAFLex
/// @VersionNote Last Revised: 2009-08-18 By Ian Smith
///
/// @Syntax MERTECH_LANGUAGE_SUPPORT OF <Server> TO <Language>
/// @Param Server     Server
/// @Param Language   Language
///
#COMMAND MERTECH_LANGUAGE_SUPPORT "OF" R "TO" R .
    MOVE !2 TO MertechInc_sArg1
    Move !4 to MertechInc_sArg2
    Call_Driver 0 ORAFlex Function 28 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_sArg2 0 RESULT MertechInc_iRet
    IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_SAVE_BUFFER_BEGIN
/// @Description
/// Initializes the extended SAVE_BUFFER
///
/// The SQL_SAVE_BUFFER_BEGIN initializes the buffer to save a set of records
/// with one save command. Each record will be moved to a free position of the buffer.
/// Once the buffer is filled to the allocated number of records, it will be saved
/// automatically. SQL_SAVE_BUFFER can be used to explicitly save the buffer
/// at any time.
///
/// The save buffer commands can be used to efficiently insert large amounts
/// of data into the database.
///
/// Note: The save buffer commands should not be used in conjunction with FINDs
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-18 By Ian Smith
/// @See         SQL_SAVE_BUFFER_BEGIN SQL_SAVE_BUFFER_END SQL_SAVE_BUFFER
///
/// @Syntax SQL_SAVE_BUFFER_BEGIN Of <FileNo|FileName> to <Buffer_Size>
/// @Param FileNum      is the File Number
/// @Param FileName     is the File Name
/// @Param Buffer_Size  Size of the Buffer to SAVE
/// @Example
/// // This example initializes the Buffer with 10 extended buffers and
/// // through the command will save 1000 registers in table SALESP.
/// // These 1000 records will be recorded in blocks of 10 records each.
/// // SQL_SAVE_BUFFER_END is called to indicate that the saving of the
/// // extended buffer has finished.
///
/// // SQL_COMMIT_STMT is called commit the transaction.
/// // Instead of using SQL_COMMIT, saving can be done within
/// // a BEGIN_TRANSACTION / END_TRANSACTION block.
/// open salesp
///
/// SQL_SAVE_BUFFER_BEGIN OF SALESP TO 10
///
/// For windowindex From 1 to 1000
///     move windowindex to salesp.id
///     move ("name"*string(windowindex)) to salesp.name
///     SQL_SAVE_BUFFER OF SALESP
///     showln WINDOWINDEX
///
/// Loop
///
/// SQL_SAVE_BUFFER_END of SALESP
/// SQL_COMMIT_STMT

#COMMAND SQL_SAVE_BUFFER_BEGIN "OF" R "TO" R .
    DO_GETFILENUMBER_DRIVERNAME !2
    If (MertechInc_DriverName EQ ORAFLEX or MertechInc_DriverName EQ SQLFLEX or MertechInc_DriverName EQ MDSDB2 or MertechInc_DriverName EQ MDSPgSQL) Begin
        MOVE !4 TO MertechInc_sArg1
        IF (MertechInc_DriverName EQ ORAFLEX OR MertechInc_DriverName EQ MDSDB2) Call_Driver MertechInc_FileNumber MertechInc_DriverName FUNCTION 20 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 0 RESULT MertechInc_iRet
        Else                                                                     Call_Driver MertechInc_FileNumber MertechInc_DriverName Function 8  CALLBACK 0 PASSING MertechInc_Blank MertechInc_sArg1 1 RESULT MertechInc_iRet
        IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
    END
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_SAVE_BUFFER
/// @Description
/// Moves the current record in the buffer of a file to the save buffer.
///
/// SQL_SAVE_BUFFER is used to save a set of record at a time instead of
/// using one record buffer. For instance, a save buffer of 10 can be
/// specified that will move 10 records to a record buffer and then save
/// them with one command (see SQL_SAVE_BUFFER_BEGIN).
/// If an 11th record is moved to the buffer the 10 records in the
/// save buffer will be saved automatically and the 11th record will
/// be saved as the 1st record in the cleared SAVE buffer.
///
/// This feature is useful when moving large amount of data from one
/// table to another. This can also be used in speed optimizations by
/// starting one transaction and saving 10 records at a time.
///
/// For an example, see SQL_SAVE_BUFFER_BEGIN
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-18 By Ian Smith
///
/// @Syntax SQL_SAVE_BUFFER Of <FileNo|FileName>
/// @Param FileNum      is the File Number
/// @Param FileName     is the File Name
///
#COMMAND SQL_SAVE_BUFFER "OF" R .
    DO_GETFILENUMBER_DRIVERNAME !2
    If (MertechInc_DriverName EQ ORAFLEX or MertechInc_DriverName EQ SQLFLEX or MertechInc_DriverName EQ MDSDB2 or MertechInc_DriverName EQ MDSPgSQL) Begin
        If (MertechInc_DriverName EQ ORAFLEX or MertechInc_DriverName EQ MDSDB2) Call_Driver MertechInc_FileNumber MertechInc_DriverName Function 20 CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 1 RESULT MertechInc_iRet
        Else                                                                     Call_Driver MertechInc_FileNumber MertechInc_DriverName Function 8  CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 2 RESULT MertechInc_iRet
        IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
    END
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_SAVE_BUFFER_END
/// @Description Indicates the end of the extended record buffer and forces
/// the driver to save any data in the buffer to the SQL backend
///
/// For an example, see SQL_SAVE_BUFFER_BEGIN
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-18 By Ian Smith
/// @See         SQL_SAVE_BUFFER_BEGIN SQL_SAVE_BUFFER_END SQL_SAVE_BUFFER
///
/// @Syntax SQL_SAVE_BUFFER_END Of <FileNo|FileName>
/// @Param FileNum      is the File Number
/// @Param FileName     is the File Name
///
#COMMAND SQL_SAVE_BUFFER_END "OF" R .
    DO_GETFILENUMBER_DRIVERNAME !2
    If (MertechInc_DriverName EQ ORAFLEX or MertechInc_DriverName EQ SQLFLEX or MertechInc_DriverName EQ MDSDB2 or MertechInc_DriverName EQ MDSPgSQL) Begin
        If (MertechInc_DriverName EQ ORAFLEX or MertechInc_DriverName EQ MDSDB2) Call_Driver MertechInc_FileNumber MertechInc_DriverName Function 20 CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 2 RESULT MertechInc_iRet
        Else                                                                     Call_Driver MertechInc_FileNumber MertechInc_DriverName Function 8  CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 4 RESULT MertechInc_iRet
        IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
    END
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_SAVE_SET_ATTRIBUTES
/// @Description Unknown - Not in help - Not call by any other macros
/// @Status      Internal
/// @Drivers     SQLFlex
/// @VersionNote Last Revised: 2009-08-18 By Ian Smith
///
/// @Syntax ??? ??? ???
///
#COMMAND SQL_SAVE_SET_ATTRIBUTES "OF" R "DISABLED""KBYTES""ROWS" #L "TABLOCK"""
    DO_GETFILENUMBER_DRIVERNAME !2
    If (MertechInc_DriverName EQ SQLFLEX) Begin
        #IFSAME !3 DISABLED
        #ELSE
            #CHECK !4 _FG#L
            #IFSAME !3 KBYTES
                Move ("KILOBYTES_PER_BATCH = " + String(!4)) to MertechInc_sArg1
            #ELSE
                Move ("ROWS_PER_BATCH = " + String(!4)) to MertechInc_sArg1
            #ENDIF

            #IF !0 > 4
                Move (MertechInc_sArg1 + ", TABLOCK") to MertechInc_sArg1
            #ENDIF
        #ENDIF
        Call_Driver MertechInc_FileNumber MertechInc_DriverName Function 8 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 7 RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        ENABLE_TRACE_ON
/// @Description Enables driver level tracing to the specified file.
///
/// Turning on the trace programmatically and using it in conjunction
/// with SQL_TEXT_MESSAGE is a good way to study particular problems
/// you encounter in the driver.
///
/// Trace files can become extremely large, and only turning them
/// on in specific modules keeps the size down, and SQL_TEXT_MESSAGE
/// allows you to tie in spots in your application code to
/// the trace the driver generates.
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-18 By Ian Smith
/// @See ENABLE_TRACE_ON DISABLE_TRACE_ON SQL_TEXT_MESSAGE
///
/// @Syntax ENABLE_TRACE_ON to <File Name> Debug_Level | DETAIL_LEVEL1 | DETAIL_LEVEL2 | DETAIL_LEVEL3 | {blank}
/// @Param File Name    Trace log file path and name
/// @Param Trace Level  DETAIL_LEVEL1 | DETAIL_LEVEL2 | DETAIL_LEVEL3 | {blank}
///
/// @Usage ENABLE_TRACE_ON TO "C:\testsql.log" DEBUG_LEVEL
///
#COMMAND ENABLE_TRACE_ON TO R "ERROR_LEVEL""DEBUG_LEVEL""DETAIL_LEVEL1""DETAIL_LEVEL2""DETAIL_LEVEL3"""
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        Move !2 to MertechInc_sArg1
        #IF (!0=3)
            #IFSAME !3 ERROR_LEVEL
                Move -1 to MertechInc_sArg2
            #ELSE
                #IFSAME !3 DEBUG_LEVEL
                    Move 0 to MertechInc_sArg2
                #ELSE
                    #IFSAME !3 DETAIL_LEVEL1
                        Move 1 to MertechInc_sArg2
                    #ELSE
                        #IFSAME !3 DETAIL_LEVEL2
                            Move 2 to MertechInc_sArg2
                        #ELSE
                            Move 3 to MertechInc_sArg2
                        #ENDIF
                    #ENDIF
                #ENDIF
            #ENDIF
        #ELSE
            Move 0 to MertechInc_sArg2
        #ENDIF

        Call_Driver 0 MertechInc_DriverName Function 15 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_sArg2 0 RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND // ENABLE_TRACE_ON

//=============================================================================
/// @Name        DISABLE_TRACE_ON
/// @Description Disable driver tracing.
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-18 By Ian Smith
/// @See ENABLE_TRACE_ON DISABLE_TRACE_ON SQL_TEXT_MESSAGE
///
/// @Syntax DISABLE_TRACE_ON
///
#COMMAND DISABLE_TRACE_ON .
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        Call_Driver 0 MertechInc_DriverName Function 15 CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 1 RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        CREATE_TABLE_FROM_DAT_FILE
/// @Description Create a server table from a DataFlex .DAT file.
///
/// Note: DF_STRUCTEND_OPT_FORCE_INVK and DF_STRUCTEND_OPT_OLD_INVK_NAME
/// are deprecated and are only for backwards compatibility with
/// pre v8 drivers.
///
/// DF_STRUCTEND_OPT_FORCE_NOT_NULL forces all fields to be created as NOT NULL.
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-19 By Ian Smith
///
/// @Syntax CREATE_TABLE_FROM_DAT_FILE <FileNum> [<RestructureOptions> [<TableName>]]
/// @Param FileNum             is the File Number
/// @Param RestructureOptions  is the restructuring options to be used
/// (DF_STRUCTEND_OPT_FORCE_INVK, DF_STRUCTEND_OPT_OLD_INVK_NAME,
///  DF_STRUCTEND_OPT_FORCE_NOT_NULL)
/// @Param TableName           is the table name to be used to name the new table instead the original DAT file physical name
///
/// @Usage CREATE_TABLE_FROM_DAT_FILE CUSTOMER.File_Number
/// @Usage CREATE_TABLE_FROM_DAT_FILE CUSTOMER.File_Number DF_STRUCTEND_OPT_FORCE_INVK
/// @Usage CREATE_TABLE_FROM_DAT_FILE CUSTOMER.File_Number (DF_STRUCTEND_OPT_FORCE_INVK, ;
///                  DF_STRUCTEND_OPT_OLD_INVK_NAME, DF_STRUCTEND_OPT_FORCE_NOT_NULL)
/// @Usage CREATE_TABLE_FROM_DAT_FILE CUSTOMER.File_Number DF_STRUCTEND_OPT_NONE "CustomerTable"
/// @Usage CREATE_TABLE_FROM_DAT_FILE CUSTOMER.File_Number (DF_STRUCTEND_OPT_FORCE_INVK ;
///                  + DF_STRUCTEND_OPT_OLD_INVK_NAME) "CustomerTable"
///
#COMMAND CREATE_TABLE_FROM_DAT_FILE R
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        #IF (!0 > 1)
            Move !2 to MertechInc_iArg
            #IF (!0 > 2)
                Move !3 to MertechInc_sArg1
            #ELSE
                Move MertechInc_Blank to MertechInc_sArg1
            #ENDIF
        #ELSE
            Move 0 to MertechInc_iArg
            Move MertechInc_Blank to MertechInc_sArg1
        #ENDIF

        If (MertechInc_DriverName = ORAFlex) Call_Driver !1 MertechInc_DriverName Function CALLDRV_ORA_CREATE_TABLE_FROM_DAT CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank MertechInc_iArg RESULT MertechInc_iRet
        Else                                 Call_Driver !1 MertechInc_DriverName Function CALLDRV_CREATE_TABLE_FROM_DAT     CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank MertechInc_iArg RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        CONVERT_DAT_FILE
/// @Description
/// Use CONVERT_DAT_FILE to migrate a table from Dataflex to SQL
/// The table and indexes will be created, and the data copied over.
///
/// Note: DF_STRUCTEND_OPT_FORCE_INVK and DF_STRUCTEND_OPT_OLD_INVK_NAME
/// are deprecated and are only for backwards compatibility with
/// pre v8 drivers.
///
/// DF_STRUCTEND_OPT_FORCE_NOT_NULL forces all fields to be created as NOT NULL.
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-19 By Ian Smith
///
/// @Syntax CONVERT_DAT_FILE <FileNum> [<RestructureOptions> [<TableName>]]
/// @Param FileNum             is the File Number
/// @Param RestructureOptions  is the restructuring options to be used (DF_STRUCTEND_OPT_FORCE_INVK + DF_STRUCTEND_OPT_OLD_INVK_NAME)
/// @Param TableName           is the table name to be used to name the new table instead the original DAT file physical name
///
/// @Usage CONVERT_DAT_FILE CUSTOMER.File_Number
/// @Usage CONVERT_DAT_FILE CUSTOMER.File_Number DF_STRUCTEND_OPT_FORCE_INVK
/// @Usage CONVERT_DAT_FILE CUSTOMER.File_Number (DF_STRUCTEND_OPT_FORCE_INVK, ;
///                  DF_STRUCTEND_OPT_OLD_INVK_NAME, DF_STRUCTEND_OPT_FORCE_NOT_NULL)
/// @Usage CONVERT_DAT_FILE CUSTOMER.File_Number DF_STRUCTEND_OPT_NONE "CustomerTable"
///                  CONVERT_DAT_FILE CUSTOMER.File_Number ;
/// @Usage (DF_STRUCTEND_OPT_FORCE_INVK + DF_STRUCTEND_OPT_OLD_INVK_NAME) "CustomerTable"
///
#COMMAND CONVERT_DAT_FILE R
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        #IF (!0 > 1)
            Move !2 to MertechInc_iArg
            #IF (!0 > 2)
                Move !3 to MertechInc_sArg1
            #ELSE
                Move MertechInc_Blank to MertechInc_sArg1
            #ENDIF
        #ELSE
            Move 0 to MertechInc_iArg
            Move MertechInc_Blank to MertechInc_sArg1
        #ENDIF

        Call_Driver !1 MertechInc_DriverName Function CALLDRV_CONVERT_DAT_FILE CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank MertechInc_iArg RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        SET_DEFAULT_FILE_CASING
/// @Description
/// Set the global file name casing standard to be used when creating a new table,
/// or restructuring existing tables.
///
/// By default all table and field names are created (as of version 11) in the case
/// given. This macro allows you to control the casing and if useful if
/// you want backwards compatibility with embedded SQL or existing tables
/// from older drivers, where the default case was uppercasing.
///
/// The default casing may also be controlled through mertech.ini
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-10-22 By Marcelo Nachbar
/// @See SET_DEFAULT_FILE_CASING GET_DEFAULT_FILE_CASING
///
/// @Syntax SET_DEFAULT_FILE_CASING TO FILE_CASING_UPPER|FILE_CASING_LOWER|FILE_CASING_KEEP
/// @Param FileCasing          is the choose file name casing that can be Upper, Lower or Keep the casing
///
/// @Usage SET_DEFAULT_FILE_CASING TO FILE_CASING_UPPER
/// @Usage SET_DEFAULT_FILE_CASING TO FILE_CASING_LOWER
/// @Usage SET_DEFAULT_FILE_CASING TO FILE_CASING_KEEP
#COMMAND SET_DEFAULT_FILE_CASING TO R .
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        Move !2 to MertechInc_sArg1
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_DEFAULT_FILE_CASING CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank CALLDRV_VALUE_SET RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        GET_DEFAULT_FILE_CASING
/// @Description Get the global gile name casing standard
/// used when creating or restructuring tables
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-10-22 By Marcelo Nachbar
/// @See SET_DEFAULT_FILE_CASING GET_DEFAULT_FILE_CASING
///
/// @Syntax GET_DEFAULT_FILE_CASING TO <FileCasing>
/// @Param FileCasing          is the file name casing that is currently defined
///
/// @Usage GET_DEFAULT_FILE_CASING TO liFileCasing
#COMMAND GET_DEFAULT_FILE_CASING TO R .
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_DEFAULT_FILE_CASING CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank CALLDRV_VALUE_GET RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
        Move MertechInc_iRet to !2
    End
#ENDCOMMAND

//=============================================================================
/// @Name        SET_DEFAULT_TABLESPACE
/// @Description Set the default tablespace to be used when creating a new
/// table using Dataflex database API commands.
/// @Status      Public
/// @Drivers     ORAFlex, PgFlex
/// @VersionNote Last Revised: 2010-01-21 By Marcelo Nachbar
/// @See SET_DEFAULT_TABLESPACE GET_DEFAULT_TABLESPACE SET_DEFAULT_INDEX_TABLESPACE GET_DEFAULT_INDEX_TABLESPACE
///
/// @Syntax SET_DEFAULT_TABLESPACE TO Value
/// @Param Value               is the tablespace name to be used
///
/// @Usage SET_DEFAULT_TABLESPACE TO "Users"
#COMMAND SET_DEFAULT_TABLESPACE TO R .
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        Move !2 to MertechInc_sArg1
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_GLOBAL_SETTING CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank GLOBAL_SETTING_TABLESPACE_SET RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        GET_DEFAULT_TABLESPACE
/// @Description Get the default tablespace to be used when creating a new
/// table using Dataflex database API commands.
/// @Status      Public
/// @Drivers     ORAFlex, PgFlex
/// @VersionNote Last Revised: 2010-01-21 By Marcelo Nachbar
/// @See SET_DEFAULT_TABLESPACE GET_DEFAULT_TABLESPACE SET_DEFAULT_INDEX_TABLESPACE GET_DEFAULT_INDEX_TABLESPACE
///
/// @Syntax GET_DEFAULT_TABLESPACE TO <Variable>
/// @Param Variable            is a variable to keep the tablespace name
///
/// @Usage GET_DEFAULT_TABLESPACE TO lsTableSpace
#COMMAND GET_DEFAULT_TABLESPACE TO R .
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        MOVE (REPEAT(" ",255)) to MertechInc_sArg1
        CALL_DRIVER 0 MertechInc_DriverName FUNCTION CALLDRV_GLOBAL_SETTING CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank GLOBAL_SETTING_TABLESPACE_GET RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
        [  ERR ] Move ""               to !2
        [ ~ERR ] Move MertechInc_sArg1 to !2
    End
#ENDCOMMAND

//=============================================================================
/// @Name        SET_DEFAULT_INDEX_TABLESPACE
/// @Description Set the default index tablespace to be used when creating a
/// new table using Dataflex database API commands.
/// @Status      Public
/// @Drivers     ORAFlex, PgFlex
/// @VersionNote Last Revised: 2010-01-21 By Marcelo Nachbar
/// @See SET_DEFAULT_TABLESPACE GET_DEFAULT_TABLESPACE SET_DEFAULT_INDEX_TABLESPACE GET_DEFAULT_INDEX_TABLESPACE
///
/// @Syntax SET_DEFAULT_INDEX_TABLESPACE TO Value
/// @Param Value               is the tablespace name to be used
///
/// @Usage SET_DEFAULT_INDEX_TABLESPACE TO "Users"
#COMMAND SET_DEFAULT_INDEX_TABLESPACE TO R .
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        Move !2 to MertechInc_sArg1
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_GLOBAL_SETTING CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank GLOBAL_SETTING_INDEX_TABLESPACE_SET RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        GET_DEFAULT_INDEX_TABLESPACE
/// @Description Get the default index tablespace to be used when creating a new
/// table using Dataflex database API commands.
/// @Status      Public
/// @Drivers     ORAFlex, PgFlex
/// @VersionNote Last Revised: 2010-01-21 By Marcelo Nachbar
/// @See SET_DEFAULT_TABLESPACE GET_DEFAULT_TABLESPACE SET_DEFAULT_INDEX_TABLESPACE GET_DEFAULT_INDEX_TABLESPACE
///
/// @Syntax GET_DEFAULT_INDEX_TABLESPACE TO <Variable>
/// @Param Variable            is a variable to keep the index tablespace name
///
/// @Usage GET_DEFAULT_INDEX_TABLESPACE TO lsTableSpace
#COMMAND GET_DEFAULT_INDEX_TABLESPACE TO R .
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        MOVE (REPEAT(" ",255)) to MertechInc_sArg1
        CALL_DRIVER 0 MertechInc_DriverName FUNCTION CALLDRV_GLOBAL_SETTING CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank GLOBAL_SETTING_INDEX_TABLESPACE_GET RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
        [  ERR ] Move ""               to !2
        [ ~ERR ] Move MertechInc_sArg1 to !2
    End
#ENDCOMMAND

//=============================================================================
/// @Name        ENABLE_SCRIPTING
/// @Description Initialize the sql script and INT file generation from the
/// current table restructuring without commiting any change
///
/// See the Programmer's Guide for more information, under
/// "Propagating Changes to Customer Sites"
///
/// @Status      Public
/// @Drivers     MySQLFlex, ORAFlex, PgFlex, SQLFlex
/// @VersionNote Last Revised: 2010-12-13 By Marcelo Nachbar
/// @See ENABLE_SCRIPTING DISABLE_SCRIPTING GET_SQL_SCRIPT_CHUNK GET_INT_CHUNK
///
/// @Syntax ENABLE_SCRIPTING
///
/// @Usage ENABLE_SCRIPTING
#COMMAND ENABLE_SCRIPTING
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin

        Call_Driver 0 MertechInc_DriverName Function CALLDRV_RESTRUCTURE_SCRIPT CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank CALLDRV_RESTRUCTURE_SCRIPT_ENABLE RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        DISABLE_SCRIPTING
/// @Description De-Initialize the sql script and INT file generation
/// from the current table restructuring
/// without commiting any change
///
/// See the Programmer's Guide for more information, under
/// "Propagating Changes to Customer Sites"
///
/// @Status      Public
/// @Drivers     MySQLFlex, ORAFlex, PgFlex, SQLFlex
/// @VersionNote Last Revised: 2010-12-13 By Marcelo Nachbar
/// @See ENABLE_SCRIPTING DISABLE_SCRIPTING GET_SQL_SCRIPT_CHUNK GET_INT_CHUNK
///
/// @Syntax DISABLE_SCRIPTING
///
/// @Usage DISABLE_SCRIPTING
#COMMAND DISABLE_SCRIPTING
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin

        Call_Driver 0 MertechInc_DriverName Function CALLDRV_RESTRUCTURE_SCRIPT CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank CALLDRV_RESTRUCTURE_SCRIPT_DISABLE RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

Function MertechInc_GET_RESTRUCTURE_SCRIPT Global Integer iLong Integer iOffset Returns String
    Local Integer iChuck_Size
    Local String sChunk

    //Get current Chuck size & pre size string
    Call_Driver 0 MertechInc_DriverName Function CALLDRV_CHUNK_SIZE CALLBACK 0 PASSING iChuck_Size MertechInc_Blank 1 RESULT MertechInc_iRet
    Get MertechInc_Pre_Size_String iChuck_Size to sChunk

    //Get data
    Call_Driver 0 MertechInc_DriverName Function CALLDRV_RESTRUCTURE_SCRIPT CALLBACK 0 PASSING sChunk iOffset iLong RESULT MertechInc_iRet

    // Replace insert a CR before any LF character
    Move (Replaces(Character(10), sChunk, Character(13)+Character(10))) to sChunk

    Function_Return sChunk
End_Function


//=============================================================================
/// @Name        GET_SQL_SCRIPT_CHUNK
/// @Description Get a chunk of data from the sql script that was
/// generated for the current table restructuring changes
///
/// See the Programmer's Guide for more information, under
/// "Propagating Changes to Customer Sites"
///
/// @Status      Public
/// @Drivers     MySQLFlex, ORAFlex, PgFlex, SQLFlex
/// @VersionNote Last Revised: 2010-12-13 By Marcelo Nachbar
/// @See ENABLE_SCRIPTING DISABLE_SCRIPTING GET_SQL_SCRIPT_CHUNK GET_INT_CHUNK
///
/// @Syntax GET_SQL_SCRIPT_CHUNK COLUMN OFFSET <offset> TO <variable> <length>
/// @Param offset   data is returned starting at offset
/// @Param variable Variable to receive the returned data
/// @Param length   The length of data returned
#COMMAND GET_SQL_SCRIPT_CHUNK "OFFSET" R "TO" R R .
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        Get MertechInc_GET_RESTRUCTURE_SCRIPT CALLDRV_RESTRUCTURE_SCRIPT_GET_CHUNK_SQL !2 To !4
        If MertechInc_iRet EQ -1 Begin
            INDICATE ERR True
            Move 0 to !5
        End
        Else Move MertechInc_iRet to !5
    End
#ENDCOMMAND

//=============================================================================
/// @Name        GET_INT_CHUNK
/// @Description Get a chunk of data from the INT file which was generated for
/// the current table restructuring changes
///
/// See the Programmer's Guide for more information, under
/// "Propagating Changes to Customer Sites"
///
/// @Status      Public
/// @Drivers     MySQLFlex, ORAFlex, PgFlex, SQLFlex
/// @VersionNote Last Revised: 2010-12-13 By Marcelo Nachbar
/// @See ENABLE_SCRIPTING DISABLE_SCRIPTING GET_SQL_SCRIPT_CHUNK GET_INT_CHUNK
///
/// @Syntax GET_INT_CHUNK COLUMN OFFSET <offset> TO <variable> <length>
/// @Param offset   data is returned starting at offset
/// @Param variable Variable to receive the returned data
/// @Param length   The length of data returned
#COMMAND GET_INT_CHUNK OFFSET R to R R .
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        Get MertechInc_GET_RESTRUCTURE_SCRIPT CALLDRV_RESTRUCTURE_SCRIPT_GET_CHUNK_INT !2 To !4
        If MertechInc_iRet EQ -1 Begin
            INDICATE ERR True
            Move 0 to !5
        End
        Else Move MertechInc_iRet to !5
    End
#ENDCOMMAND

//=============================================================================
/// @Name        REPORT_STMT
/// @Description This version of the REPORT macro allows you to use
/// embedded SQL to fetch data.
///
/// The find commands usually performed by the REPORT macro are replaced
/// with calls to fetch data from an embedded SQL cursor
///
/// @Status      Public
/// @Drivers     n/a
/// @VersionNote Last Revised: 2009-08-19 By Ian Smith
///
/// @Syntax See DataFlex / Visual DataFlex documentation
///
/// @Comment This is a copy of the standard DataFlex REPORT macro with the find
/// @Comment commands replace with SQL_FETCH_NEXT_ROW. The Comments have been
/// @Comment reformatted to improve readability.
/// @Example
/// /Header
/// __/__/____                                                        Page ___.
///                 MERTECH DATA SYSTEMS, INC. - NOT FOR RESALE
///
/// ID   NAME
///
/// /Body
/// ____ _________________________
/// /Total
/// Records printed = _______.
/// /*
///
///
/// OPEN SALESP
/// direct_output "con:"
/// // Write the complete SELECT statement to retrieve the expected records from your REPORT
/// // Must include the expression to qualify the required records and specify the order by as well
///
/// sql_set_stmt of salesp to "select recnum, id, name from SALESP where recnum > 5 order by id"
/// sql_prepare_stmt of salesp
/// sql_bindcolumns_stmt of salesp to salesp.recnum salesp.id salesp.name
/// sql_execute_stmt of salesp
///
/// Report_stmt SALESP By Index.1
///
/// Section Header
///     Sysdate Header.1
///     Move PageCount to Header.2
///     output header
///
/// Section Body
///     Print Salesp.id   to Body.1
///     Print Salesp.name to Body.2
///     output body
/// Section Total
///
/// Return
/// ReportEnd

#COMMAND REPORT_STMT T "BY""DOWN" VFW%LGR "BREAK"""
    #CHECK !1.RECNUM _UVCWGL
    Integer RECCOUNT
    #SET P$ 0
    !A [] $82 |CI20000 |VI10                //MOVEINT 20000 TO LINECOUNT    - start with a full page
    !A [] $82 |CI0 RECCOUNT                 //MOVE 0 TO RECCOUNT
    !A [] $207                              //BREAKINIT                     - init breakpoints
    #IFDEF FIRSTREC
    #ELSE
        #Replace FIRSTREC |!C
    #ENDIF
    !A [] $4028 |CI0 |CI0 FIRSTREC~         //INDICATE FIRSTREC TRUE        - used for subtotals

    SQL_FETCH_NEXT_ROW of !1.FILE_NUMBER    //Retrieve the First Row
    //#IFSAME !2 BY                         // FIND first record
    //    FIND GE !1 BY !3
    //#ELSE
    //    FIND LE !1 BY !3
    //#ENDIF
    [~Found] Goto END$OF$REPORT
    !A [] $144                              //CLEARSCREEN                   - start with a clear screen
    RPT.Loop:                               //INDICATE SELECT TRUE      // default for SELECT
    #IFDEF SELECT
    #ELSE
        #Replace SELECT |!C
    #ENDIF
    !A [] $4028 |CI0 |CI0 SELECT~
    !A [] $42 |CL0                          //GOSUB RPT.SELECTION     // go to user selection
    #FREF RPT.SELECTION !a
    !A [~ SELECT] $41 |CL0                  //[NOT SELECT] GOTO RPT.CONT        // test SELECT
    #FREF RPT.CONT !a
    BREAK$ !5 !6 !7 !8 !9                   //set breakpoints
    #SET X$ !p                              //set up to break down
    [not FIRSTREC] BREAK$DOWN RPT.SUBTOTAL  //break down for SUBTOTAL
    #SET X$ 0                               //set up to break up
    !A [] $C4 !1.RECNUM                     //RELATE !1           // get related records
    BREAK$UP RPT.SUBHEADER                  //break up for SUBHEADER
    !A [] $083 RECCOUNT |CI0                //INCREMENT RECCOUNT
    !A [] $42 |CL0                          //GOSUB RPT.BODY          // print body
    #FREF RPT.BODY !a
    !A [] $4028 |CI0 |CI0 FIRSTREC          //INDICATE FIRSTREC FALSE     // not first any more
    RPT.CONT:
    SQL_FETCH_NEXT_ROW of !1.FILE_NUMBER    //Retrieve the next Row from current query
    //#IFSAME !2 BY                         // FIND next record
    //    FIND GT !1 BY !3
    //#ELSE
    //    FIND LT !1 BY !3
    //#ENDIF
    !A [] $46                               //KEYCHECK            // check keyboard
    !A [Found ~ KEYPRESS] $41 RPT.Loop      //[FOUND NOT KEYPRESS] GOTO RPT.LOOP    // if ok, loop
    !A [Found KEYPRESS]   $42 |CL0          //[KEYPRESS]  GOSUB RPT.KEYPRESS    // user can disable KEYPRESS
    #FREF RPT.KEYPRESS !a
    !A [Found ~ KEYPRESS] $41 RPT.Loop
    #SET X$ !p                              //set up for break down
    End.of.REPORT:
    [~ FIRSTREC]  BREAK$DOWN RPT.SUBTOTAL $X    // break down for last subtotals
    !A [~ FIRSTREC] $42 |CL0                //[FIRSTREC]  GOSUB RPT.TOTAL       // print TOTAL
    #FREF RPT.TOTAL !a
    !A [] $41 |CL0                          //GOTO END$OF$REPORT      // GOTO end
    #FREF END$OF$REPORT !a
    NEWPAGE:                                //GOSUB RPT.HEADER      // new page, print HEADER
    !A [] $42 |CL0
    #FREF RPT.HEADER !a
    #SET X$ 0                               //this will reprint the page headers if included //
    [not FIRSTREC] BREAK$PRT SUBHEADER      //reprint pages
    !A [] $43 |CI0                          //RETURN              // end of NEWPAGE
    RPT.SELECTION:                          //selection starts after REPORT
#ENDCOMMAND

//=============================================================================
/// @Name        GET_SERVER_CFG
/// @Description Retrieve Server attributes from the database
/// @Status      Internal
/// @Drivers     All
/// @VersionNote Last Revised: 2011-02-25 By Marcelo
///
/// @Syntax GET_SERVER_CFG [SERVER_REVISION | SERVER_MIN_REVISION | SUPPORT_DESC      | SUPPORT_CASE |
/// @Syntax                 SERVER_VERSION  | SERVER_ENCODING     | CONNECTION_ACTIVE] OF <SERVER NAME> TO <RESULT>
/// @Param SERVER_REVISON     Retrieve Server major revision
/// @Param SUPPORT_DESC       <RESULT> is 1 if Server supports Descending index segments
/// @Param SUPPORT_CASE       <RESULT> is 1 if Server supports Case Insensitive index segments
/// @Param SERVER_VERSION     Retrieve Complete Server Version Description
/// @Param SERVER_ENCODING    Retrieve the Server Encoding
/// @Param CONNECTION_ACTIVE  Retrieve the Connection status. DFTRUE means connection is active
/// @Param CITEXT_SUPPORT     <RESULT> is 1 if Server supports citext a PostgreSQL data type
/// @Comment Code suggests that GET_SERVER_CFG CONNECTION_ACTIVE Of Server Database TO sValue is valid.
///
/// @Usage GET_SERVER_CFG SERVER_VERSION of "Win2K" to sValue
///
#COMMAND GET_SERVER_CFG "SERVER_REVISION""SERVER_MIN_REVISION""SUPPORT_DESC""SUPPORT_CASE""SERVER_VERSION""SERVER_ENCODING""CONNECTION_ACTIVE""CITEXT_SUPPORT" "OF" R
    DO_GETFILENUMBER_DRIVERNAME 0

    //workout server name
    #IFSAME !1 CONNECTION_ACTIVE
        #IFSAME !4 to
            Move !3 to MertechInc_sArg1
        #ELSE
            #CHECK !5 "TO"
            Move (!3+"*"+!4) to MertechInc_sArg1
        #ENDIF
    #ELSE
        #CHECK !4 "TO"
        Move !3 to MertechInc_sArg1
    #ENDIF

    //Workout attribute to get
    #IFSAME !1 SERVER_REVISION
        Move 0 to MertechInc_iArg
    #ELSE
        #IFSAME !1 SUPPORT_DESC
            Move 1 to MertechInc_iArg
        #ELSE
            #IFSAME !1 SUPPORT_CASE
                Move 2 to MertechInc_iArg
            #ELSE
                #IFSAME !1 SERVER_MIN_REVISION
                    Move 3 to MertechInc_iArg
                #ELSE
                    #IFSAME !1 SERVER_VERSION
                        Move 4 to MertechInc_iArg
                    #ELSE
                        #IFSAME !1 SERVER_ENCODING
                           Move 5 to MertechInc_iArg
                        #ELSE
                            #IFSAME !1 CONNECTION_ACTIVE
                               Move 6 to MertechInc_iArg
                            #ELSE
                               Move 7 to MertechInc_iArg
                            #ENDIF
                        #ENDIF
                    #ENDIF
                #ENDIF
            #ENDIF
        #ENDIF
    #ENDIF

    #IFSAME !4 to
        Get MertechInc_GET_SERVER_CFG MertechInc_sArg1 MertechInc_iArg to !5
    #ELSE
        Get MertechInc_GET_SERVER_CFG MertechInc_sArg1 MertechInc_iArg to !6
    #ENDIF

    If MertechInc_iRet EQ -1 INDICATE ERR True
#ENDCOMMAND

Function MertechInc_GET_SERVER_CFG Global String sServer Integer iAttribute Returns String
    Local String sReturnValue

    Get MertechInc_Pre_Size_String 512 to sReturnValue

    Call_Driver 0 MertechInc_DriverName Function CALLDRV_GET_SERVER_CFG CALLBACK 0 PASSING sServer sReturnValue iAttribute RESULT MertechInc_iRet

    //If iAttribute = SERVER_VERSION or SERVER_ENCODING then return sReturnValue
    //else we need to return MertechInc_iRet
    If ((iAttribute = 4) or (iAttribute = 5)) Function_Return sReturnValue
    Else                                      Function_Return MertechInc_iRet
End_Function

//=============================================================================
/// @Name        GET_CONNECTION_STATUS
/// @Description Retrieve the connection status for the specified server
/// @Status      Internal
/// @Drivers     All
/// @VersionNote Last Revised: 2009-09-25 By Ian Smith
///
/// @Syntax GET_CONNECTION_STATUS of <serverName> [<databaseName>] to <variable>
/// @Param serverName    Server Name
/// @Param databaseName  Database Name
/// @Param variable      DFTRUE means connection is active
///
#COMMAND GET_CONNECTION_STATUS "OF" R
    #IFSAME !3 TO
        GET_SERVER_CFG CONNECTION_ACTIVE OF !2 TO !4
    #ELSE
        #CHECK !4 "TO"
        GET_SERVER_CFG CONNECTION_ACTIVE OF !2 !3 TO !5
    #ENDIF
#ENDCOMMAND

//=============================================================================
/// @Name        GET_CLIENT_CFG
/// @Description Returns the client character encoding (or encoding ID) information.
/// @Status      Internal
/// @Drivers     MySQLFlex & PgFlex
/// @VersionNote Last Revised: 2009-09-25 By Ian Smith
///
/// @Syntax GET_CLIENT_CFG [ENCODING | ENCODING_ID] of <Server> [<MySQL_Database>] to <Var>
/// @Param Server           Server name to get encoding of
/// @Param MySQL_Database   Database if   is the File Name
/// @Param Var              Variable to hold returned value
///
#COMMAND GET_CLIENT_CFG "ENCODING""ENCODING_ID" "OF" R
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_DriverName EQ MySQLFLEX  or MertechInc_DriverName EQ MDSPgSQL) Begin
        Get MertechInc_Pre_Size_String 255 to MertechInc_sArg2

        #IFSAME !5 to
            Move (!3+"*"+!4) to MertechInc_sArg1
        #ELSE
            #CHECK !4 "TO"
            Move !3 to MertechInc_sArg1
        #ENDIF

        #IFSAME !1 ENCODING
            Move 0 to MertechInc_iArg
        #ELSE
            Move 3 to MertechInc_iArg
        #ENDIF

        Call_Driver MertechInc_FileNumber MertechInc_DriverName Function CALLDRV_CLIENT_CFG CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_sArg2 MertechInc_iArg RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
        Else Begin
            #IFSAME !5 to
                Move MertechInc_sArg2 to !6
            #ELSE
                Move MertechInc_sArg2 to !5
            #ENDIF
        End
    End
#ENDCOMMAND

//=============================================================================
/// @Name        SET_CLIENT_CFG
/// @Description Returns the client character encoding (or encoding ID) information.
/// @Status      Internal
/// @Drivers     MySQLFlex & PgFlex
/// @VersionNote Last Revised: 2009-09-25 By Ian Smith
///
/// @Syntax SET_CLIENT_CFG [ENCODING | UNIQUE_CHECKS] of <Server> [<MySQL_Database>] to <Value>
/// @Param Server           Server name to get encoding of
/// @Param MySQL_Database   Database if   is the File Name
/// @Param Value            Value to set
///
/// @Comment ENCODING - Set the Client Encoding
/// @Comment UNIQUE_CHECKS {DFTRUE/DFFALSE} - enable/disable uniqueness checks for secondary indexes in InnoDB tables
///
#COMMAND SET_CLIENT_CFG "ENCODING""UNIQUE_CHECKS" "OF" R
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_DriverName EQ MySQLFLEX  or MertechInc_DriverName EQ MDSPgSQL) Begin
        #IFSAME !1 ENCODING
            Move 1 to MertechInc_iArg
            #IFSAME !4 to
                Move !3 to MertechInc_sArg1
                Move !5 to MertechInc_sArg2
            #ELSE
                Move (!3+"*"+!4) to MertechInc_sArg1
                Move !6 to MertechInc_sArg2
            #ENDIF
        #ELSE
            #CHECK !4 "TO"
            Move !3 to MertechInc_sArg1
            Move 2 to MertechInc_iArg
            Move !5 to MertechInc_sArg2
        #ENDIF

        Call_Driver MertechInc_FileNumber MertechInc_DriverName Function CALLDRV_CLIENT_CFG CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_sArg2 MertechInc_iArg RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        CALL_DB2_PROCEDURE
/// @Description Executes a DB2 Server stored procedure.
/// @Status      Public
/// @Drivers     DB2Flex
/// @VersionNote Last Revised: 2009-08-19 By Ian Smith
///
/// @Syntax CALL_DB2_PROCEDURE <OWNER> <STORED_PROC> {PASSING <ARG1> {. <ARGn>}}
/// @Param Owner        Name of the Procedure's Owner.
/// @Param Stored_Proc  Full name of the stored procedure being called.
/// @Param Arg1..Argn   Arguments passed to the procedure.
///
#COMMAND CALL_DB2_PROCEDURE R R "PASSING""BINDING"""
    LOAD_DRIVER "MertechInc_DB2"

    INDICATE MertechInc_bThereIsBinding False

    #IF (!0>3)
        DO_CHECK_BINDING !4 !5 !6 !7 !8 !9
    #ENDIF

    MOVE 0 TO MertechInc_iParamCount
    INDICATE ERR FALSE
    SQL_SET_STMT TO "CALL "
    SQL_APPEND_STMT TO !1
    SQL_APPEND_STMT TO "."
    SQL_APPEND_STMT TO !2
    SQL_APPEND_STMT TO " "
    #IF (!0>2)
        DDO_PASS_ARGUMENTS  !3 !4 !5 !6 !7 !8 !9
        IF (MertechInc_iParamCount > 0) SQL_APPEND_STMT TO ")"
    #ENDIF

    MOVE (UPPERCASE(!1)) TO MertechInc_sArg1
    Move (UPPERCASE(!2)) to MertechInc_sArg2

    Call_Driver 0 MDSDB2 Function 23 CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_sArg2 0 RESULT MertechInc_iRet
    IF MertechInc_iRet NE -1 BEGIN
        MOVE 0 TO MertechInc_iParamCount

        SQL_PREPARE_STMT
        #IF (!0>2)
        DDO_BIND_PARAMETERS  !3 !4 !5 !6 !7 !8 !9
        #ENDIF

        SQL_EXECUTE_STMT
        [ NOT ERR ] BEGIN
            If ( MertechInc_iParamCount GT 0 ) BEGIN
                MOVE 0 TO MertechInc_iParamCount
                [not MertechInc_bThereIsBinding] Begin
                    #IF (!0>3)
                        DDO_GET_BIND_PARAMETERS  !4 !5 !6 !7 !8 !9
                    #ENDIF
                END
            END
        END
    END
    ELSE INDICATE ERR TRUE
#ENDCOMMAND // CALL_DB2_PROCEDURE

//=============================================================================
/// @Name        GET_RESULTS
/// @Description Returns the initial result set.
/// @Status      Public
/// @Drivers     DB2Flex
/// @VersionNote Last Revised: 2009-08-19 By Ian Smith
///
/// @Syntax GET_RESULTS
///
#COMMAND GET_RESULTS .
    CALL_DRIVER 0 MDSDB2 FUNCTION CALLDRV_GET_RESULTS CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 0 RESULT MertechInc_iRet
    IF MertechInc_iRet EQ -1 INDICATE FINDERR TRUE
    ELSE INDICATE FOUND TRUE
#ENDCOMMAND

//=============================================================================
/// @Name        GET_MORE_RESULTS
/// @Description Returns remaining values not retrieved with GET_RESULT.
/// @Status      Public
/// @Drivers     DB2Flex
/// @VersionNote Last Revised: 2009-08-19 By Ian Smith
///
/// @Syntax GET_MORE_RESULTS
///
#COMMAND GET_MORE_RESULTS .
    CALL_DRIVER 0 MDSDB2 FUNCTION CALLDRV_GET_MORE_RESULTS CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 0 RESULT MertechInc_iRet
    IF MertechInc_iRet EQ -1 INDICATE FINDERR TRUE
    ELSE BEGIN
        INDICATE FOUND TRUE
        GET_RESULTS
    END
#ENDCOMMAND

//=============================================================================
/// @Name        GET_CURRENT_USER_NAME
/// @Description Retrieves the login name of the current user.
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-12 By Ian Smith
///
/// @Syntax GET_CURRENT_USER_NAME OF <Server_Name> TO <VAR>
/// @Param Server_Name  Name of the Server from which the current user is to be retrieved
/// @Param Var          Variable to receive the User's Name
///
#COMMAND GET_CURRENT_USER_NAME "OF" R "TO" R .
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        Move !2 to MertechInc_sArg1
        Get MertechInc_Pre_Size_String 255 to MertechInc_sArg2
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_GET_CURRENT_USER_NAME CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_sArg2 0 RESULT MertechInc_iRet
        Move MertechInc_sArg2 to !4
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        GET_CURRENT_USER_PASSWORD
/// @Description Retrieves the password used to login to the server.
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-12 By Ian Smith
///
/// @Syntax GET_CURRENT_USER_NAME OF <Server_Name> TO <VAR>
/// @Param Server_Name  Name of the Server from which the current user is to be retrieved
/// @Param Var          Variable to receive the User's Name
///
/// @Usage GET_CURRENT_USER_PASSWORD of sMainServer to sPASSWORD
/// @Usage GET_CURRENT_USER_PASSWORD of '' to sPASSWORD
///
#COMMAND GET_CURRENT_USER_PASSWORD "OF" R "TO" R .
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        Move !2 to MertechInc_sArg1
        Get MertechInc_Pre_Size_String 255 to MertechInc_sArg2

        Call_Driver 0 MertechInc_DriverName Function CALLDRV_GET_CURRENT_USER_PASSWORD CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_sArg2 0 RESULT MertechInc_iRet
        Move MertechInc_sArg2 to !4
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        CREATE_DB2_DATABASE
/// @Description Creates a DB2 database with the same DataFlex collating sequence
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-12 By Ian Smith
///
/// @Syntax CREATE_DB2_DATABASE <DB Name> <DB Alias> <Code Set> <Territory> [<Path> <Node Name> <User ID><Password>]
/// @Param DB Name     Name of the database being created
/// @Param DB Alias    Alias Name applied to the database being created
/// @Param Code Set    Code Set used by the database being created
/// @Param Territory   Territory associated to the database being created
/// @Param Path        Location of the database                                    - Optional
/// @Param Node Name   Name of the machine (node) where the database is to reside  - Optional
/// @Param User ID     User ID owning the database                                 - Optional
/// @Param Password    Password of the User owning the database                    - Optional
///
#COMMAND CREATE_DB2_DATABASE R R R R
    Move !1 to MertechInc_sArg1 // Set DB Name
    Call_Driver 0 MDSDB2 Function CALLDRV_CREATE_DB CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 0 RESULT MertechInc_iRet
    Move !2 to MertechInc_sArg1 // Set DB Alias
    Call_Driver 0 MDSDB2 Function CALLDRV_CREATE_DB CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 1 RESULT MertechInc_iRet
    Move !3 to MertechInc_sArg1 // Set Code Set
    Call_Driver 0 MDSDB2 Function CALLDRV_CREATE_DB CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 2 RESULT MertechInc_iRet
    Move !4 to MertechInc_sArg1 // Set Territory
    Call_Driver 0 MDSDB2 Function CALLDRV_CREATE_DB CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 3 RESULT MertechInc_iRet

    #IF (!0 > 4)
        Move !5 to MertechInc_sArg1 // Set Path
        Call_Driver 0 MDSDB2 Function CALLDRV_CREATE_DB CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 4 RESULT MertechInc_iRet
        #IF (!0 = 8)
            Move !6 to MertechInc_sArg1 // Set NodeName
            Call_Driver 0 MDSDB2 Function CALLDRV_CREATE_DB CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 5 RESULT MertechInc_iRet
            Move !7 to MertechInc_sArg1 // Set UserId
            Call_Driver 0 MDSDB2 Function CALLDRV_CREATE_DB CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 6 RESULT MertechInc_iRet
            Move !8 to MertechInc_sArg1 // Set UserId
            Call_Driver 0 MDSDB2 Function CALLDRV_CREATE_DB CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 7 RESULT MertechInc_iRet
        #ENDIF
    #ENDIF

    CALL_DRIVER 0 MDSDB2 FUNCTION CALLDRV_CREATE_DB CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 8 RESULT MertechInc_iRet
    IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_OPEN_CURSOR_STMT
/// @Description
/// Creates a new SQL Cursor. If the server name is specified,
/// cursor will be opened from that server, otherwise the server to
/// which you are currently logged in is the one that is used.
///
/// This command allows you to keep multiple SQL statements open at
/// the same time.
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-19 By Ian Smith
/// @See SQL_OPEN_CURSOR_STMT SQL_CLOSE_CURSOR_STMT SQL_SET_CURRENT_CURSOR_STMT SQL_GET_CURRENT_CURSOR_STMT
///
/// @Syntax SQL_OPEN_CURSOR_STMT OF <Server Name> |TO <CursorVar>
/// @Param Server Name   Name of the Server to open the cursor on
/// @Param CursorVar     Variable to hold returned cursor handle
///
/// @Usage SQL_OPEN_CURSOR_STMT OF "server" TO iCursor1
/// @Usage SQL_OPEN_CURSOR_STMT TO iCursor2
/// @Example
/// string id name
/// integer rec
/// integer Cursor1 Cursor2
///
/// Open two cursors, and interleave looping through the records
/// switching which cursor is the active one
///
/// SQL_SET_CURRENT_CURSOR_STMT TO Cursor1
///
/// SQL_SET_STMT TO "SELECT RECNUM, ID, NAME FROM SALESP ORDER"
/// SQL_APPEND_STMT TO " BY " "NAME DESC"
/// SQL_PREPARE_STMT
/// SQL_EXECUTE_STMT
///
/// SQL_SET_CURRENT_CURSOR_STMT TO Cursor2
///
/// SQL_SET_STMT TO "SELECT RECNUM, CUSTOMER_NUMBER, NAME FROM CUSTOMER ORDER"
/// SQL_APPEND_STMT TO " BY " "CUSTOMER_NUMBER "
/// SQL_PREPARE_STMT
/// SQL_EXECUTE_STMT
///
/// repeat
///     SQL_SET_CURRENT_CURSOR_STMT TO Cursor1
///     SQL_FETCH_NEXT_ROW INTO REC ID NAME
///     [ found ] begin
///        SHOWLN "SALESP : " REC " " ID " " NAME
///     end
///
///     SQL_SET_CURRENT_CURSOR_STMT TO Cursor2
///     SQL_FETCH_NEXT_ROW INTO REC ID NAME
///     [ found ] begin
///         SHOWLN "CUSTOMER : " REC " " ID " " NAME
///     end
/// until [ finderr ]
///
/// SQL_CLOSE_CURSOR_STMT to Cursor1
/// SQL_CLOSE_CURSOR_STMT to Cursor2

#COMMAND SQL_OPEN_CURSOR_STMT "OF""TO""" R
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        #IFSAME !1 of
            Move !2 to MertechInc_sArg1
            #CHECK !3 "TO"
        #ELSE
            Move "" to MertechInc_sArg1
            #CHECK !1 "TO"
        #ENDIF

        Call_Driver 0 MertechInc_DriverName Function CALLDRV_OPEN_EMBEDDED_CURSOR CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 0 RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
        #IFSAME !1 of
            Move MertechInc_iRet to !4
        #ELSE
            Move MertechInc_iRet to !2
        #ENDIF
    End
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_CLOSE_CURSOR_STMT
/// @Description Closes an SQL cursor previously opened with SQL_OPEN_CURSOR_STMT
///
/// See SQL_OPEN_CURSOR_STMT for an example.
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-19 By Ian Smith
/// @See SQL_OPEN_CURSOR_STMT SQL_CLOSE_CURSOR_STMT SQL_SET_CURRENT_CURSOR_STMT SQL_GET_CURRENT_CURSOR_STMT
///
/// @Syntax SQL_CLOSE_CURSOR_STMT OF <Server Name> |TO <Cursor>
/// @Param Server Name   Name of the Server to close the cursor on
/// @Param Cursor        Handle of cursor to close
///
/// @Usage SQL_CLOSE_CURSOR_STMT OF "server" TO iCursor1
/// @Usage SQL_CLOSE_CURSOR_STMT TO iCursor2
///
#COMMAND SQL_CLOSE_CURSOR_STMT "OF""TO""" R
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        #IFSAME !1 of
            Move !2 to MertechInc_sArg1
            #CHECK !3 "TO"
            Move !4 to MertechInc_iArg
        #ELSE
            Move "" to MertechInc_sArg1
            #CHECK !1 "TO"
            Move !2 to MertechInc_iArg
        #ENDIF

        Call_Driver 0 MertechInc_DriverName Function CALLDRV_CLOSE_EMBEDDED_CURSOR CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank MertechInc_iArg RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_SET_CURRENT_CURSOR_STMT
/// @Description Make a cursor opened with SQL_OPEN_CURSOR_STMT the current cursor
///
/// See SQL_OPEN_CURSOR_STMT for an example.
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-19 By Ian Smith
/// @See SQL_OPEN_CURSOR_STMT SQL_CLOSE_CURSOR_STMT SQL_SET_CURRENT_CURSOR_STMT SQL_GET_CURRENT_CURSOR_STMT
///
/// @Syntax SQL_SET_CURRENT_CURSOR_STMT OF <Server Name> |TO <Cursor>
/// @Param Server Name   Name of the Server to set the current cursor on
/// @Param Cursor        Handle of cursor to make current
///
/// @Usage SQL_SET_CURRENT_CURSOR_STMT OF "Win2K" TO iCursor1
/// @Usage SQL_SET_CURRENT_CURSOR_STMT TO iCursor2
///
#COMMAND SQL_SET_CURRENT_CURSOR_STMT "OF""TO""" R
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        #IFSAME !1 of
            Move !2 to MertechInc_sArg1
            #CHECK !3 "TO"
            Move !4 to MertechInc_iArg
        #ELSE
            Move "" to MertechInc_sArg1
            #CHECK !1 "TO"
            Move !2 to MertechInc_iArg
        #ENDIF

        Call_Driver 0 MertechInc_DriverName Function CALLDRV_SET_CURRENT_EMBEDDED_CURSOR CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank MertechInc_iArg RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_GET_CURRENT_CURSOR_STMT
/// @Description Get current cursor handle
///
/// See SQL_OPEN_CURSOR_STMT for an example.
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-19 By Ian Smith
/// @See SQL_OPEN_CURSOR_STMT SQL_CLOSE_CURSOR_STMT SQL_SET_CURRENT_CURSOR_STMT SQL_GET_CURRENT_CURSOR_STMT
///
/// @Syntax SQL_GET_CURRENT_CURSOR_STMT OF <Server Name> |TO <CursorVar>
/// @Param Server Name   Name of the Server to open the cursor on
/// @Param CursorVar     Variable to hold returned cursor handle
///
/// @Usage SQL_GET_CURRENT_CURSOR_STMT OF "Win2K" TO iCursor1
/// @Usage SQL_GET_CURRENT_CURSOR_STMT TO iCursor2
///
#COMMAND SQL_GET_CURRENT_CURSOR_STMT "OF""TO""" R
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        #IFSAME !1 of
            Move !2 to MertechInc_sArg1
            #CHECK !3 "TO"
        #ELSE
            Move "" to MertechInc_sArg1
            #CHECK !1 "TO"
        #ENDIF

        Call_Driver 0 MertechInc_DriverName Function CALLDRV_GET_CURRENT_EMBEDDED_CURSOR CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 0 RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
        #IFSAME !1 of
            Move MertechInc_iRet to !4
        #ELSE
            Move MertechInc_iRet to !2
        #ENDIF
    End
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_SET_MAX_CURSORS_STMT
/// @Description Sets the maximum number of simultaneous cursors allowed.
/// @Status      Deprecated
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-19 By Ian Smith
///
/// @Syntax SQL_SET_MAX_CURSORS_STMT OF <Server Name> |TO <MaxCursors>
/// @Param Server Name   Name of the Server to set max cursors on
/// @Param MaxCursors    Number of cursors allowed
///
/// @Usage SQL_SET_MAX_CURSORS_STMT OF "Win2K" TO 50
/// @Usage SQL_SET_MAX_CURSORS_STMT TO 25
///
#COMMAND SQL_SET_MAX_CURSORS_STMT "OF""TO""" R
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        #IFSAME !1 of
            Move !2 to MertechInc_sArg1
            #CHECK !3 "TO"
            Move !4 to MertechInc_iArg
        #ELSE
            Move "" to MertechInc_sArg1
            #CHECK !1 "TO"
            Move !2 to MertechInc_iArg
        #ENDIF

        Call_Driver 0 MertechInc_DriverName Function CALLDRV_SET_MAX_EMBEDDED_CURSOR CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank MertechInc_iArg RESULT MertechInc_iRet
        IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
    End
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_GET_MAX_CURSORS_STMT
/// @Description Retrieves the maximum number of cursors allowed.
/// @Status      Deprecated
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-19 By Ian Smith
///
/// @Syntax SQL_GET_MAX_CURSORS_STMT OF <Server Name> |TO <CursorsVar>
/// @Param Server Name   Name of the Server to get Max cursor on
/// @Param CursorsVar    Variable to hold returned max cursors
///
/// @Usage SQL_GET_MAX_CURSORS_STMT OF "Win2K" TO iMaxCursors
/// @Usage SQL_GET_MAX_CURSORS_STMT TO iMaxCursors
///
#COMMAND SQL_GET_MAX_CURSORS_STMT "OF""TO""" R
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        #IFSAME !1 of
            Move !2 to MertechInc_sArg1
            #CHECK !3 "TO"
        #ELSE
            Move "" to MertechInc_sArg1
            #CHECK !1 "TO"
        #ENDIF

        Call_Driver 0 MertechInc_DriverName Function CALLDRV_GET_MAX_EMBEDDED_CURSOR CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 0 RESULT MertechInc_iRet
        IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
        #IFSAME !1 OF
            MOVE MertechInc_iRet TO !4
        #ELSE
            MOVE MertechInc_iRet TO !2
        #ENDIF
    End
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_SET_LOCAL_TD_PATH
/// @Description Sets the directory where the driver will find the LOCAL TD files.
/// @Status      Deprecated
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-19 By Ian Smith
///
/// @Syntax SQL_SET_LOCAL_TD_PATH TO <DirectoryPath|Variable>
/// @Param DirectoryPath   Directory path were the TD files are to be located.
///
#COMMAND SQL_SET_LOCAL_TD_PATH "TO" R
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        Move !2 to MertechInc_sArg1

        Call_Driver 0 MertechInc_DriverName Function CALLDRV_LOCAL_TD_PATH CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 0 RESULT MertechInc_iRet
        IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
    End
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_GET_LOCAL_TD_PATH
/// @Description Gets the directory where the driver is looking for the LOCAL TD files.
/// @Status      Deprecated
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-19 By Ian Smith
///
/// @Syntax SQL_SET_LOCAL_TD_PATH TO <DirectoryPath|Variable>
/// @Param DirectoryPath   Directory path were the driver is looking
///
#COMMAND SQL_GET_LOCAL_TD_PATH "TO" R
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_LOCAL_TD_PATH CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank 1 RESULT MertechInc_iRet
        IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
        ELSE MOVE MertechInc_sArg1 TO !2
    End
#ENDCOMMAND

//=============================================================================
/// @Name        GET_DRIVER_REVISION
/// @Description Retrieves the version of the driver currently being used.
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-19 By Ian Smith
///
/// @Syntax GET_DRIVER_REVISION To <Var>
/// @Param Var  Variable to hold the returned driver version
///
#COMMAND GET_DRIVER_REVISION "TO" R .
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        Get MertechInc_Pre_Size_String 255 to !2
        Call_Driver 0 MertechInc_DriverName Function 0 CALLBACK 0 PASSING MertechInc_Blank !2 0 RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        GET_DRIVER_MAJOR_REVISION
/// @Description Retrieves the version of the driver currently being used.
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-08-19 By Ian Smith
///
/// @Syntax GET_DRIVER_MAJOR_REVISION To <Var>
/// @Param Var  Variable to hold the returned driver version
///
#COMMAND GET_DRIVER_MAJOR_REVISION "TO" R .
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        Get MertechInc_Pre_Size_String 255 to !2
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_LICENSE_ENVIRONMENT_SET CALLBACK 0 PASSING MertechInc_Blank !2 CALLDRV_MAJOR_REVISION RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        GET_DRIVER_LICENSE_EXPIRATION_TIME
/// @Description Retrieve the time until expiration for a trial license.
///
/// If returned value is -1 this means that the license has already expired
///
/// If returned value is 0 then this is not a temporary license
///
/// Otherwise the returned value is the number of days until expiration
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-09-26 By Ian Smith
///
/// @Syntax GET_DRIVER_LICENSE_EXPIRATION_TIME TO <Var>
/// @Param Var  Variable to hold the returned expiry value
///
/// @Example
///  use windows
///  use mertech.inc
///  load_driver "sql_drv"
///  integer iExpire
///  GET_DRIVER_LICENSE_EXPIRATION_TIME to iExpire
///  if (iExpire > 0) Begin
///      if (iExpire > 365) Send info_box ("license will expire in" * string(iExpire/365) * "year(s)")
///      else Send info_box ("license will expire in" * string(iExpire) * "day(s)")
///  End
///  Else if (iExpire = 0) Begin
///     Send info_box ("license does not expires. It is not a temporary license")
///  End
///     Else Send Info_box "license already expired"
///
#COMMAND GET_DRIVER_LICENSE_EXPIRATION_TIME "TO" R .
    DO_GETFILENUMBER_DRIVERNAME 0

    If (MertechInc_FileNumber <> -1) Begin
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_LICENSE_ENVIRONMENT_SET CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank CALLDRV_TIME_TO_LIC_EXPIRATION RESULT MertechInc_iRet
        Move MertechInc_iRet to !2
    End
#ENDCOMMAND

//=============================================================================
/// @Name        SET_DRIVER_LICENSE_EXPIRATION_WARNING
/// @Description Set up a new warning message when a temporary license
/// is about to expire
///
/// This macro command is useful for users who need a customized message instead of the regular one
/// used by the drivers. Since the license evaluation is done during
/// the Login command call (or before any OPEN calls that do an implicit login),
/// SET_DRIVER_LICENSE_EXPIRATION_WARNING
/// must be called before the first Login command call and, in this
/// case, you should use Load_Driver to make sure that the proper
/// driver is loaded already.
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-09-26 By Ian Smith
///
/// @Syntax SET_DRIVER_LICENSE_EXPIRATION_WARNING TO <WarningMessage>
/// @Param WarningMessage is the new message that will be shown
///
///
/// @Example
/// use windows
/// use mertech.inc
/// Load_Driver "sql_drv"
///
/// SET_DRIVER_LICENSE_EXPIRATION_WARNING TO "Your license is about to expire."
/// Login "localhost" "" "" "sql_drv"

#COMMAND SET_DRIVER_LICENSE_EXPIRATION_WARNING "TO" R .
    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        Move !2 to MertechInc_sArg1
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_LICENSE_ENVIRONMENT_SET CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank CALLDRV_LICENSE_EXPIRATION_WARN RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

//=============================================================================
/// @Name        GET_DRIVER_LICENSE_PATH
/// @Description Retrieve the driver license path
/// @Status      Internal
/// @Drivers     All
/// @VersionNote Last Revised: 2009-09-26 By Ian Smith
///
/// @Syntax GET_DRIVER_LICENSE_PATH TO <Variable>
/// @Param Variable Returned license path
///
#COMMAND GET_DRIVER_LICENSE_PATH "TO" R .
    Get MertechInc_GET_DRIVER_LICENSE_PATH to !2
#ENDCOMMAND

Function MertechInc_GET_DRIVER_LICENSE_PATH Global Returns String
    Local String sReturnValue

    DO_GETFILENUMBER_DRIVERNAME 0
    If (MertechInc_FileNumber <> -1) Begin
        Get MertechInc_Pre_Size_String 4096 to sReturnValue
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_LICENSE_ENVIRONMENT_SET CALLBACK 0 PASSING sReturnValue MertechInc_Blank CALLDRV_LICENSE_PATH RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End

    Function_Return sReturnValue
End_Function

//=============================================================================
/// @Name        SET_DATABASE_PORT
/// @Description Sets the TCP/IP port used to connect to the server
/// @Status      Public
/// @Drivers     MySQLFlex PgFlex
/// @VersionNote Last Revised: 2009-09-19 By Ian Smith
/// @See SET_DATABASE_PORT GET_DATABASE_PORT
///
/// @Syntax SET_DATABASE_PORT "OF" "MYSQL""PGSQL" "TO" <Port>
/// @Param Port  TCP/IP Port number
///
#COMMAND SET_DATABASE_PORT "OF" "MYSQL""PGSQL" "TO" R .
    #IFSAME !2 TO MYSQL
        MOVE MDSMySQL TO MertechInc_DriverName
    #ELSE
        MOVE MDSPGSQL TO MertechInc_DriverName
    #ENDIF

    MOVE !4 TO MertechInc_sArg1
    CALL_DRIVER 0 MertechInc_DriverName FUNCTION CALLDRV_LICENSE_ENVIRONMENT_SET CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank CALLDRV_SET_DB_PORT RESULT MertechInc_iRet
    If MertechInc_iRet EQ -1 INDICATE ERR True
#ENDCOMMAND

//=============================================================================
/// @Name        GET_DATABASE_PORT
/// @Description Retrieves the TCP/IP port used to connect to the server
/// @Status      Public
/// @Drivers     MySQLFlex PgFlex
/// @VersionNote Last Revised: 2009-09-19 By Ian Smith
/// @See SET_DATABASE_PORT GET_DATABASE_PORT
///
/// @Syntax GET_DATABASE_PORT "OF" "MYSQL""PGSQL" "TO" <Port>
/// @Param Port  TCP/IP Port number
///
#COMMAND GET_DATABASE_PORT "OF" "MYSQL""PGSQL" "TO" R .
    #IFSAME !2 TO MYSQL
        MOVE MDSMySQL TO MertechInc_DriverName
    #ELSE
        MOVE MDSPGSQL TO MertechInc_DriverName
    #ENDIF

    MOVE (REPEAT(" ",255)) to !4
    CALL_DRIVER 0 MertechInc_DriverName FUNCTION CALLDRV_LICENSE_ENVIRONMENT_SET CALLBACK 0 PASSING !4 MertechInc_Blank CALLDRV_GET_DB_PORT RESULT MertechInc_iRet
    If MertechInc_iRet EQ -1 INDICATE ERR True
#ENDCOMMAND

//=============================================================================
/// @Name        GET_SERIAL_NUMBER
/// @Description Retrieves the serial number for the driver license.
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-09-19 By Ian Smith
///
/// @Syntax GET_SERIAL_NUMBER TO <Serial>
/// @Param Serial  Variable to hold the returned serial number.
///
#COMMAND GET_SERIAL_NUMBER "TO" R .
    DO_GETFILENUMBER_DRIVERNAME 0

    MOVE (REPEAT(" ",255)) to !2
    CALL_DRIVER 0 MertechInc_DriverName FUNCTION CALLDRV_LICENSE_ENVIRONMENT_SET CALLBACK 0 PASSING MertechInc_Blank !2 CALLDRV_SERIAL_NUMBER RESULT MertechInc_iRet
    IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
#ENDCOMMAND

//=============================================================================
/// @Name        SET_DATABASE_SOCKET
/// @Description Set the socket used to connect to the server, when
/// running Dataflex under Linux/Unix connecting via Unix sockets.
/// @Status      Public
/// @Drivers     MySQLFlex
/// @VersionNote Last Revised: 2009-09-19 By Ian Smith
/// @See SET_DATABASE_SOCKET GET_DATABASE_SOCKET
///
/// @Syntax SET_DATABASE_SOCKET "OF" "MYSQL" "TO" <Socket>
/// @Param Socket  Full Socket name
///
#COMMAND SET_DATABASE_SOCKET "OF" "MYSQL" "TO" R .
    MOVE MDSMySQL TO MertechInc_DriverName

    MOVE !4 TO MertechInc_sArg1
    CALL_DRIVER 0 MertechInc_DriverName FUNCTION CALLDRV_LICENSE_ENVIRONMENT_SET CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank CALLDRV_SET_DB_SOCKET RESULT MertechInc_iRet
    If MertechInc_iRet EQ -1 INDICATE ERR True
#ENDCOMMAND

//=============================================================================
/// @Name        GET_DATABASE_SOCKET
/// @Description Get the socket used to connect to the server. (Unix based systems )
/// @Status      Public
/// @Drivers     MySQLFlex
/// @VersionNote Last Revised: 2009-09-19 By Ian Smith
/// @See SET_DATABASE_SOCKET GET_DATABASE_SOCKET
///
/// @Syntax GET_DATABASE_SOCKET "OF" "MYSQL" "TO" <Socket>
/// @Param Socket  Full Socket name
///
#COMMAND GET_DATABASE_SOCKET "OF" "MYSQL" "TO" R .
    MOVE MDSMySQL TO MertechInc_DriverName

    MOVE (REPEAT(" ",255)) to !4
    CALL_DRIVER 0 MertechInc_DriverName FUNCTION CALLDRV_LICENSE_ENVIRONMENT_SET CALLBACK 0 PASSING !4 MertechInc_Blank CALLDRV_GET_DB_SOCKET RESULT MertechInc_iRet
    If MertechInc_iRet EQ -1 INDICATE ERR True
#ENDCOMMAND

//=============================================================================
/// @Name        SET_AUTHENTICATION_MODE
/// @Description Controls if the authentication mode for login to the Oracle server
/// is default or sysdba.
/// @Status      Public
/// @Drivers     OraFlex
/// @VersionNote Last Revised: 2009-09-19 By Ian Smith
///
/// @Syntax SET_AUTHENTHICATION_MODE "OF" "ORACLE" "TO" "SYSDBA""DEFAULT"
///
#COMMAND SET_AUTHENTICATION_MODE "OF" "ORACLE" "TO" "SYSDBA""DEFAULT" .
    MOVE ORAFlex TO MertechInc_DriverName

    #IFSAME !4 SYSDBA
        MOVE 1 to MertechInc_sArg1
    #ELSE
        MOVE 0 to MertechInc_sArg1
    #ENDIF
    CALL_DRIVER 0 MertechInc_DriverName FUNCTION CALLDRV_LICENSE_ENVIRONMENT_SET CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank CALLDRV_SET_AS_SYSDBA RESULT MertechInc_iRet
    IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_ESCAPE_STRING
/// @Description Escapes a string to make it safe for use with embedded SQL.
///
/// Properly escaping strings before passing them to embedded SQL is of key
/// importance if you do not have full control over what goes into the strings,
/// and constitutes a security risk.
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-09-21 By Ian Smith
///
/// @Syntax SQL_ESCAPE_STRING OF <String> TO <Variable>
/// @Syntax SQLESCAPESTRING(<String>)
/// @Param String    String to escape
/// @Param Variable  Variable for the returned escaped string
///
/// @Usage SQL_ESCAPE_STRING of "can't" to sSafeString
/// @Usage Move (SQLESCAPESTRING(sUnsafeString)) to sSafeString
///
#COMMAND SQL_ESCAPE_STRING "OF" R "TO" R
    Get SQLESCAPESTRING !2 to !4
#ENDCOMMAND

Function SQLESCAPESTRING Global String sData Returns String
    String sReturnData

    DO_GETFILENUMBER_DRIVERNAME 0

    If (MertechInc_FileNumber <> -1) Begin
        Get MertechInc_Pre_Size_String 0 to sReturnData
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_ESCAPE_STRING CALLBACK 0 PASSING sData sReturnData 0 RESULT MertechInc_iRet
    End

    Function_Return sReturnData
End_Function

//=============================================================================
/// @Name        DIRECT_PATH_LOAD
/// @Description ???
/// @Status      Internal
/// @Drivers     OraFlex
/// @VersionNote Last Revised: 2009-09-21 By Ian Smith
///
///
#COMMAND DIRECT_PATH_LOAD "OF" R "FROM" R
    DO_GETFILENUMBER_DRIVERNAME 0

    If (MertechInc_DriverName EQ ORAFlex) Begin
        [~Err] Move !4.File_Number to MertechInc_iArg
        Call_Driver !2.File_Number ORAFlex Function CALLDRV_DIRECT_PATH_LOAD CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank MertechInc_iArg RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
        #IF (!0=5)
            #CHECK !5 RLGU#
            [~Err] Move MertechInc_iRet to !5
            [ Err] Move 0        to !5
        #ENDIF
    End
#ENDCOMMAND

//=============================================================================
/// @Name        SQL_INITIALIZE_SEQUENCE
/// @Description Initializes auto increment columns (in PostgreSQL) or sequences
/// (in Oracle) to be the highest number in the table plus one.
///
/// Use this feature if you bulk insert data into the table,
/// or if you use regular inserts and have not enable triggers for
/// recnum handling.
///
/// @Status      Public
/// @Drivers     OraFlex PgFlex
/// @VersionNote Last Revised: 2009-09-21 By Ian Smith
///
#COMMAND SQL_INITIALIZE_SEQUENCE "OF" R .
    DO_GETFILENUMBER_DRIVERNAME !2

    IF (MertechInc_DriverName EQ ORAFlex OR MertechInc_DriverName EQ PgFlex) BEGIN
        Call_Driver MertechInc_FileNumber MertechInc_DriverName Function CALLDRV_INITIALIZE_SEQUENCE CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 0 RESULT MertechInc_iRet
        IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
    End
#ENDCOMMAND

//=============================================================================
/// @Name        LOB_APPEND
/// @Description
/// Append the existing field buffer value into the assigned LOB column,
/// preserving the existing LOB column data. LOB_APPEND should be combined
/// with the LOB_WRITE macro command to fill up the LOB column with the required data.
/// Before calling this macro command, the file must have an active and locked
/// record at the buffer, otherwise error #25000 will be issued with message
/// "Record buffer is inactive."
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-09-07 By Ian Smith
/// @See LOB_APPEND LOB_LENGTH LOB_WRITE LOB_READ LOB_LOADFROMFILE LOB_ERASE LOB_TRUNCATE FLUSH_LOB_BUFFER
///
/// @Syntax LOB_APPEND OF <FileNum|FileName> <FieldNumber>
/// @Param FileNum      is the File Number
/// @Param FileName     is the File Name
/// @Param FieldNumber  is the number of the field to append
///
/// @Comment The field specified by FieldNumber has to be a Text or Binary field
/// @Comment (field type DF_TEXT or DF_BINARY). No check is done to ensure this.
///
/// @Usage LOB_APPEND OF customer 13
/// @Example
/// // Assumes the 13th field of customel is type TEXT or BINARY and named comments
/// Local Integer iLength
/// open "customel.int" as customel
/// clear customel
/// find gt customel by index.1
/// // Delete any lob data in the field, and fill it up with the contents of a file
/// Lock
/// 	LOB_TRUNCATE     of customel 13 to 0
///  	LOB_LOADFROMFILE of customel 13 FROM "." "document.pdf"
/// Unlock
/// Find Eq customel by Recnum
/// Direct_Output 'Binary: document-copy.pdf'
/// // Retrieve the chunk length and the first chunk of data into the field buffer
/// LOB_LENGTH of customel 13 to iLength
/// LOB_READ OF customel 13 First iLength
/// Write customel.comments
/// // Loop through and retrieve the following chunks and write them to a file
/// While (iLength > 0)
/// 	LOB_READ of customel 13 Next iLength
/// 	Write customel.comments
/// Loop

#COMMAND LOB_APPEND "OF" R R .
    DO_GETFILENUMBER_DRIVERNAME !2

    If (MertechInc_DriverName EQ SQLFLEX or MertechInc_DriverName EQ ORAFLEX  or MertechInc_DriverName EQ MDSMySQL or MertechInc_DriverName EQ MDSPgSQL ) Begin
        Move !3 To MertechInc_iArg

        Call_Driver MertechInc_FileNumber MertechInc_DriverName Function CALLDRV_APPEND_LOB CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank MertechInc_iArg RESULT MertechInc_iRet
        IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
    End
#ENDCOMMAND

#REPLACE SQL_LOB_APPEND LOB_APPEND

//=============================================================================
/// @Name        LOB_LENGTH
/// @Description
/// Retrieve the total length from a given LOB column. This macro command
/// must be called right after a FIND, otherwise it will not retrieve the
/// proper length value, and error #25000 will be issued with message
/// "Record is not positioned."
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-09-11 By Ian Smith
/// @See LOB_APPEND LOB_LENGTH LOB_WRITE LOB_READ LOB_LOADFROMFILE LOB_ERASE LOB_TRUNCATE FLUSH_LOB_BUFFER
///
/// @Syntax LOB_LENGTH OF <FileNum|FileName> <FieldNumber> TO <Variable>
/// @Param FileNum      is the File Number
/// @Param FileName     is the File Name
/// @Param FieldNumber  is the number of the field to append
/// @Param Variable     Variable to store the length of the LOB column
///
/// @Comment The field specified by FieldNumber has to be a Text or Binary field
/// @Comment (field type  DF_TEXT or DF_BINARY). No check is done to ensure this.
///
/// @Usage LOB_LENGTH OF customer 13 To iCol_Len
///
#COMMAND LOB_LENGTH "OF" R R "TO" R .
    DO_GETFILENUMBER_DRIVERNAME !2

    If (MertechInc_DriverName EQ SQLFLEX or MertechInc_DriverName EQ ORAFLEX  or MertechInc_DriverName EQ MDSMySQL or MertechInc_DriverName EQ MDSPgSQL ) Begin
        Move !3 to MertechInc_iArg

        Call_Driver MertechInc_FileNumber MertechInc_DriverName Function CALLDRV_LENGTH_LOB CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank MertechInc_iArg RESULT MertechInc_iRet
        MOVE MertechInc_iRet to !5
    End
#ENDCOMMAND

#Replace SQL_LOB_LENGTH LOB_LENGTH

//=============================================================================
/// @Name        LOB_READ
/// @Description
/// Read a chunk of data from a LOB column moving the read value into the assigned
/// file field buffer. Since the chunk data is going to be moved into a file
/// field buffer, the actual read value length cannot exceed the field buffer length.
///
/// Use LOB_READ FileName FieldNumber FIRST to read the first chunk of data
/// and LOB_READ FileName FieldNumber NEXT to read the remaining data.
/// LOB_READ returns a zero in the ReadLength argument when there is no more
/// data to read.
/// The LOB_READ macro command must be called right after a FIND, otherwise it
/// will not retrieve the proper length value, and an error #25000 will be
/// issued with message "Record is not positioned." Immediately after a FIND,
/// the first chunk from the LOB column is always available at the file field buffer.
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-09-11 By Ian Smith
/// @See LOB_APPEND LOB_LENGTH LOB_WRITE LOB_READ LOB_LOADFROMFILE LOB_ERASE LOB_TRUNCATE FLUSH_LOB_BUFFER
///
/// @Syntax LOB_READ OF <FileName> <FieldNumber> [FIRST | NEXT]  [<Read Length>]
/// @Param FileNum      is the File Number
/// @Param FileName     is the File Name
/// @Param FIRST        read the firs block of data
/// @Param NEXT         read the next block of data
/// @Param Read Length  Variable to store the length of the LOB column
///
/// @Comment The field specified by FieldNumber has to be a Text or Binary field
/// @Comment (field type  DF_TEXT or DF_BINARY). No check is done to ensure this.
///
/// @Usage LOB_READ OF lobtst 3 next lInputSize
///
#COMMAND LOB_READ "OF" R R "FIRST""NEXT"
    DO_GETFILENUMBER_DRIVERNAME !2

    If (MertechInc_DriverName EQ SQLFLEX or MertechInc_DriverName EQ ORAFLEX  or MertechInc_DriverName EQ MDSMySQL or MertechInc_DriverName EQ MDSPgSQL ) Begin
        Move !3 to MertechInc_iArg

        #IFSAME !4 FIRST
            MOVE "0" TO MertechInc_sArg1
        #ELSE
            MOVE "1" TO MertechInc_sArg1
        #ENDIF

        Call_Driver MertechInc_FileNumber MertechInc_DriverName Function CALLDRV_READ_LOB CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank MertechInc_iArg RESULT MertechInc_iRet
        IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
        #IF (!0=5)
            #CHECK !5 RLGU#
            IF MertechInc_iRet EQ -1 MOVE 0 TO !5
            ELSE MOVE MertechInc_iRet TO !5
        #ENDIF
    END
#ENDCOMMAND

#Replace SQL_LOB_READ LOB_READ

//=============================================================================
/// @Name        LOB_WRITE
/// @Description
/// Write the existing field buffer value into the assigned LOB column,
/// overwriting the existing LOB column data. LOB_WRITE should be combined
/// with the LOB_APPEND macro command to fill up the LOB column with the
/// required data. Before calling this macro command, the file must have
/// an active and locked record at the buffer, otherwise error #25000 will
/// be issued with message "Record buffer is inactive."
///
/// See LOB_APPEND for an example
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-09-11 By Ian Smith
/// @See LOB_APPEND LOB_LENGTH LOB_WRITE LOB_READ LOB_LOADFROMFILE LOB_ERASE LOB_TRUNCATE FLUSH_LOB_BUFFER
///
/// @Syntax LOB_WRITE OF <FileName> <FieldNumber>
/// @Param FileNum      is the File Number
/// @Param FileName     is the File Name
///
/// @Comment The field specified by FieldNumber has to be a Text or Binary field
/// @Comment (field type  DF_TEXT or DF_BINARY). No check is done to ensure this.
///
/// @Usage LOB_WRITE OF lobtst 3
///
#COMMAND LOB_WRITE "OF" R R .
    DO_GETFILENUMBER_DRIVERNAME !2

    If (MertechInc_DriverName EQ SQLFLEX or MertechInc_DriverName EQ ORAFLEX  or MertechInc_DriverName EQ MDSMySQL or MertechInc_DriverName EQ MDSPgSQL ) Begin
        Move !3 to MertechInc_iArg
        Call_Driver MertechInc_FileNumber MertechInc_DriverName Function CALLDRV_WRITE_LOB CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank MertechInc_iArg RESULT MertechInc_iRet
        IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
    End
#ENDCOMMAND

#Replace SQL_LOB_WRITE LOB_WRITE

//=============================================================================
/// @Name        LOB_LOADFROMFILE
/// @Description
/// Load an external file into a LOB column. When using LOB_LOADFROMFILE
/// with the Oracle driver, the input file must be available from the Oracle
/// database, because the load task will be done by the database.
/// To use this command you must supply the alias for the created directory object.
/// When using LOB_LOADFROMFILE with the MS SQL Server driver, the input file
/// must be a local file available to the application that is calling the command.
///
/// See LOB_APPEND for an example
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-09-11 By Ian Smith
/// @See LOB_APPEND LOB_LENGTH LOB_WRITE LOB_READ LOB_LOADFROMFILE LOB_ERASE LOB_TRUNCATE FLUSH_LOB_BUFFER
///
/// @Syntax LOB_LOADFROMFILE OF <FileName> <FieldNumber> FROM <Directory_Alias> <External_File>
/// @Param FileNum          is the File Number
/// @Param FileName         is the File Name
/// @Param Directory_Alias  Oracle : Alias for a Directory Object.  See Oracle "CREATE DIRECTORY" statement
/// @Param                  SQL Svr: Local Directory Path where input file is located
/// @Param External_File    Oracle : File must be at the server side under the Directory defined by <Directory Alias>
/// @Param                  SQL Svr: This is a local input file.
///
/// @Comment The field specified by FieldNumber has to be a Text or Binary field
/// @Comment (field type  DF_TEXT or DF_BINARY). No check is done to ensure this.
///
/// @Usage LOB_LOADFROMFILE OF CUSTOMER 13 FROM "TEST" "mertech.inc"
/// @Usage LOB_LOADFROMFILE of CUSTOMER 13 from "c:\test\" "mertech.inc"
///
#COMMAND LOB_LOADFROMFILE "OF" R R "FROM" R R .
    DO_GETFILENUMBER_DRIVERNAME !2

    If (MertechInc_DriverName EQ SQLFLEX or MertechInc_DriverName EQ ORAFLEX  or MertechInc_DriverName EQ MDSMySQL or MertechInc_DriverName EQ MDSPgSQL ) Begin
        Move !3 to MertechInc_iArg
        MOVE !5 TO MertechInc_sArg1
        Move !6 to MertechInc_sArg2

        Call_Driver MertechInc_FileNumber MertechInc_DriverName Function CALLDRV_LOADFROMFILE_LOB CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_sArg2 MertechInc_iArg RESULT MertechInc_iRet
        IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
    End
#ENDCOMMAND

#Replace SQL_LOB_LOADFROMFILE LOB_LOADFROMFILE

//=============================================================================
/// @Name        LOB_ERASE
/// @Description
/// Erase a portion of data from a LOB column. A DF_TEXT field is erased
/// by filling it with blanks. A DF_BINARY field is erased by filling it with 0x0.
/// Before calling this macro command, the file must have an active and
/// locked record at the buffer, otherwise error #25000 will be issued
/// with message "Record buffer is inactive."
///
/// See LOB_APPEND for an example
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-09-11 By Ian Smith
/// @See LOB_APPEND LOB_LENGTH LOB_WRITE LOB_READ LOB_LOADFROMFILE LOB_ERASE LOB_TRUNCATE FLUSH_LOB_BUFFER
///
/// @Syntax LOB_ERASE OF <FileName> <FieldNumber> <Amt> <Offset>
/// @Param FileNum  is the File Number
/// @Param FileName is the File Name
/// @Param Amt      Amount of data to erase
/// @Param Offset   Starting Position to erase (1 based)
///
/// @Comment The field specified by FieldNumber has to be a Text or Binary field
/// @Comment (field type  DF_TEXT or DF_BINARY). No check is done to ensure this.
///
/// @Usage LOB_ERASE OF CUSTOMER 13 150 1
///
#COMMAND LOB_ERASE "OF" R R R R .
    DO_GETFILENUMBER_DRIVERNAME !2

    If (MertechInc_DriverName EQ SQLFLEX or MertechInc_DriverName EQ ORAFLEX  or MertechInc_DriverName EQ MDSMySQL or MertechInc_DriverName EQ MDSPgSQL ) Begin
        Move !3 to MertechInc_iArg
        MOVE !4 TO MertechInc_sArg1
        Move !5 to MertechInc_sArg2

        Call_Driver MertechInc_FileNumber MertechInc_DriverName Function CALLDRV_ERASE_LOB CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_sArg2 MertechInc_iArg RESULT MertechInc_iRet
        IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
    End
#ENDCOMMAND

#Replace SQL_LOB_ERASE LOB_ERASE

//=============================================================================
/// @Name        LOB_TRUNCATE
/// @Description
/// Truncate data from a LOB column to a given length.
///
/// Before calling this macro command, the file must have an active and
/// locked record at the buffer, otherwise error #25000 will be issued
/// with message "Record buffer is inactive."
///
/// See LOB_APPEND for an example
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-09-11 By Ian Smith
/// @See LOB_APPEND LOB_LENGTH LOB_WRITE LOB_READ LOB_LOADFROMFILE LOB_ERASE LOB_TRUNCATE FLUSH_LOB_BUFFER
///
/// @Syntax LOB_TRUNCATE OF <FileName> <FieldNumber> TO <NewLen>
/// @Param FileNum  is the File Number
/// @Param FileName is the File Name
/// @Param NewLen   New length for LOB column
///
/// @Comment The field specified by FieldNumber has to be a Text or Binary field
/// @Comment (field type  DF_TEXT or DF_BINARY). No check is done to ensure this.
///
/// @Usage LOB_TRUNCATE OF CUSTOMER 13 50
///
#COMMAND LOB_TRUNCATE "OF" R R "TO" R .
    DO_GETFILENUMBER_DRIVERNAME !2

    If (MertechInc_DriverName EQ SQLFLEX or MertechInc_DriverName EQ ORAFLEX  or MertechInc_DriverName EQ MDSMySQL or MertechInc_DriverName EQ MDSPgSQL ) Begin
        Move !3 to MertechInc_iArg
        MOVE !5 TO MertechInc_sArg1

        Call_Driver MertechInc_FileNumber MertechInc_DriverName Function CALLDRV_TRUNCATE_LOB CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank MertechInc_iArg RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

#Replace SQL_LOB_TRUNCATE LOB_TRUNCATE

//=============================================================================
/// @Name        FLUSH_LOB_BUFFER
/// @Description
/// Send the data that was loaded into an LOB column to the database.
/// This is necessary due to MySQL's architecture.
///
/// See LOB_APPEND for an example
///
/// @Status      Public
/// @Drivers     MySQLFlex
/// @VersionNote Last Revised: 2009-09-21 By Ian Smith
/// @See LOB_APPEND LOB_LENGTH LOB_WRITE LOB_READ LOB_LOADFROMFILE LOB_ERASE LOB_TRUNCATE FLUSH_LOB_BUFFER
///
/// @Syntax FLUSH_LOB_BUFFER OF <FileName>
/// @Param FileName is the file name to flush lob buffer
///
/// @Usage FLUSH_LOB_BUFFER OF CUSTOMER
///
#COMMAND FLUSH_LOB_BUFFER "OF" R
    DO_GETFILENUMBER_DRIVERNAME !2

    IF (MertechInc_DriverName EQ MySQLFlex) BEGIN
        Call_Driver MertechInc_FileNumber MertechInc_DriverName Function CALLDRV_END_SAVERECORD CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 0 RESULT MertechInc_iRet
        IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
    End
#ENDCOMMAND

#Replace SQL_END_SAVERECORD FLUSH_LOB_BUFFER

//=============================================================================
/// @Name        SQL_ENABLE_RECONNECT
/// @Description Allow MySql Driver to auto reconnect after a time-out.
///
/// Driver auto-reconnect feature handles the issue where MySQL
/// will kick off a user after inactivity.
///
/// @Status      Deprecated
/// @Drivers     MySQL
/// @VersionNote Last Revised: 2009-09-11 By Ian Smith
///
/// @Syntax SQL_ENABLE_RECONNECT of <ServerName> to dftrue/dffalse
/// @Param ServerName  Server Name.
///
/// @Usage SQL_ENABLE_RECONNECT Of sServerID To dftrue
///
#COMMAND SQL_ENABLE_RECONNECT "OF" R "TO" R .
    DO_GETFILENUMBER_DRIVERNAME 0

    MOVE !2 TO MertechInc_sArg1
    IF (MertechInc_DriverName EQ MySQLFlex);
        CALL_DRIVER 0 MertechInc_DriverName FUNCTION CALLDRV_ENABLE_RECONNECT CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank !4 RESULT MertechInc_iRet
    IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
#ENDCOMMAND

//=============================================================================
/// @Name        CALL_MYSQL_STORED_PROCEDURE
/// @Description Call a stored procedures on a MySQL server.
/// @Status      Public
/// @Drivers     MySQLFlex
/// @VersionNote Last Revised: 2009-09-21 By Ian Smith
///
/// @Syntax CALL_MYSQL_STORED_PROCEDURE sProcName [PASSING sParam1 [sParam2 . sParamn]]
/// @Param sProcName    The procedure to execute
/// @Param sParam1.n    Parameters to be passed in or out of the procedure
/// @Example
///
/// // This assumes that "CREATE PROCEDURE p1 () SELECT * FROM SALESP;"
/// // has been executed to create a procedure on the server
///
/// #include mertech.inc
/// string   sServer
/// String   sRecID sName sID
///
/// login "server" "user" "password" "MDSMYSQL"
///
/// CALL_MYSQL_STORED_PROCEDURE "p1();"
///
/// While (found)
///   sql_fetch_next_row INTO sRecID sName sID
///   showln "->" sRecID ", " sName ", " sID
/// Loop

#COMMAND CALL_MYSQL_STORED_PROCEDURE R "PASSING"""
    Move 0 to Mertech_iMySQLParam
    SQL_SET_PROCEDURE_NAME !1 NUMPAR (!0-2)

    #IF (!0>2)
        DO_SET_ALL_PROCEDURE_PARAMATERS !3 !4 !5 !6 !7 !8 !9
    #ENDIF

    SQL_PROCEDURE_EXECUTE

    #IF (!0>2)
        Move 0 to Mertech_iMySQLParam
        DO_GET_ALL_PROCEDURE_PARAMATERS !3 !4 !5 !6 !7 !8 !9
    #ENDIF
#ENDCOMMAND

//=============================================================================
/// @Name        DO_SET_ALL_PROCEDURE_PARAMATERS
/// @Description Sets the parameters for a MySQL stored procedures call
/// @Status      Internal
/// @Drivers     MySQLFlex
/// @VersionNote Last Revised: 2009-09-21 By Ian Smith
///
/// @Syntax DO_SET_ALL_PROCEDURE_PARAMATERS [sParam1 [sParam2 . sParamn]]
/// @Param sParam1.n    Parameters for the stored procedure
///
#COMMAND DO_SET_ALL_PROCEDURE_PARAMATERS
    Increment Mertech_iMySQLParam
    SQL_SET_PROCEDURE_PARAMETER Mertech_iMySQLParam to !1 IN_OUT
    #IF !0>1
        DO_SET_ALL_PROCEDURE_PARAMATERS !2 !3 !4 !5 !6 !7 !8 !9
    #ENDIF
#ENDCOMMAND

//=============================================================================
/// @Name        DO_GET_ALL_PROCEDURE_PARAMATERS
/// @Description Gets the parameters for a MySQL stored procedures call
/// @Status      Internal
/// @Drivers     MySQLFlex
/// @VersionNote Last Revised: 2009-09-21 By Ian Smith
///
/// @Syntax DO_GET_ALL_PROCEDURE_PARAMATERS [sParam1 [sParam2 . sParamn]]
/// @Param sParam1.n    Parameters for the stored procedure
///
#COMMAND DO_GET_ALL_PROCEDURE_PARAMATERS
    Increment Mertech_iMySQLParam
    SQL_GET_PROCEDURE_PARAMETER Mertech_iMySQLParam to !1
    #IF !0>1
        DO_GET_ALL_PROCEDURE_PARAMATERS !2 !3 !4 !5 !6 !7 !8 !9
    #ENDIF
#ENDCOMMAND

//=============================================================================
/// @Name        CALL_MYSQL_STORED_FUNCTION
/// @Description Call a stored function on a MySQL server.
/// @Status      Public
/// @Drivers     MySQLFlex
/// @VersionNote Last Revised: 2009-09-21 By Ian Smith
///
/// @Syntax CALL_MYSQL_STORED_FUNCTION sProcName RETURNS sRetVal [PASSING sParam1 [sParam2 . sParamn]]
/// @Param sProcName    The procedure to execute
/// @Param sRetVal      Variable for the return value
/// @Param sParam1.n    Parameters to be passed in or out of the procedure
///
#COMMAND CALL_MYSQL_STORED_FUNCTION R "RETURNS" R "PASSING"""
    Move 0 to Mertech_iMySQLParam

    #IF (!0>4)
        SQL_SET_FUNCTION_NAME !1 NUMPAR (!0-4)
        DO_SET_ALL_FUNCTION_PARAMATERS !5 !6 !7 !8 !9
    #ELSE
        SQL_SET_FUNCTION_NAME !1 NUMPAR 0
    #ENDIF

    SQL_PROCEDURE_EXECUTE

    SQL_GET_FUNCTION_RETURN to !3
#ENDCOMMAND

//=============================================================================
/// @Name        DO_SET_ALL_FUNCTION_PARAMATERS
/// @Description Sets the parameters for a MySQL stored function call
/// @Status      Internal
/// @Drivers     MySQLFlex
/// @VersionNote Last Revised: 2009-09-21 By Ian Smith
///
/// @Syntax DO_SET_ALL_FUNCTION_PARAMATERS [sParam1 [sParam2 . sParamn]]
/// @Param sParam1.n    Parameters for the stored function
///
#COMMAND DO_SET_ALL_FUNCTION_PARAMATERS
    Increment Mertech_iMySQLParam
    SQL_SET_FUNCTION_PARAMETER Mertech_iMySQLParam to !1 IN
    #IF !0>1
        DO_SET_ALL_FUNCTION_PARAMATERS !2 !3 !4 !5 !6 !7 !8 !9
    #ENDIF
#ENDCOMMAND

//=============================================================================
/// @Name        GET_NO_AVAILABLE_SQLSERVERS
/// @Description Get the number of available MS_SQL servers detected in the network.
///
/// The SQL server browser service must be started, and appropriate firewall
/// settings be opened for browsing to work.
///
/// Use this macro in conjunction with GET_SQLSERVER_NAME
/// to enumerate the servers found.
///
/// @Status      Public
/// @Drivers     SQLFlex
/// @VersionNote Last Revised: 2009-09-21 By Ian Smith
/// @See GET_NO_AVAILABLE_SQLSERVERS GET_SQLSERVER_NAME
///
/// @Syntax GET_NO_AVAILABLE_SQLSERVERS TO Var
/// @Param Var  Variable to hold returned value
///
#COMMAND GET_NO_AVAILABLE_SQLSERVERS "TO" R .
    Get SQL_AVAILABLE_SQL_SERVERS to !2
#ENDCOMMAND

Function SQL_AVAILABLE_SQL_SERVERS Global Returns Integer
    Call_Driver 0 SQLFLEX Function CALLDRV_ENUMERATE_SERVER CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank CALLDRV_ENUMERATE_SERVER_COUNT RESULT MertechInc_iRet

    Function_Return MertechInc_iRet
End_Function

#Replace AvailableSQLServers SQL_AVAILABLE_SQL_SERVERS

//=============================================================================
/// @Name        GET_SQLSERVER_NAME
/// @Description Returns the name of the server specified by index,
/// up to the value returned by GET_NO_AVAILABLE_SQLSERVERS
///
/// The SQL server browser service must be started, and appropriate firewall
/// settings be opened for browsing to work.
///
/// Use this macro in conjunction with GET_SQLSERVER_NAME
/// to enumerate the servers found.
/// @Status      Public
/// @Drivers     SQLFlex
/// @VersionNote Last Revised: 2009-09-21 By Ian Smith
/// @See GET_NO_AVAILABLE_SQLSERVERS GET_SQLSERVER_NAME
///
/// @Syntax SQL_AVAILABLE_SQL_SERVER_NAME iIndex TO sName
/// @Param iIndex  1 based index of the server name to return
/// @Param sName   Variable to hold returned name
///
#COMMAND GET_SQLSERVER_NAME R "TO" R .
    Get SQL_AVAILABLE_SQL_SERVER_NAME !1 to !3
#ENDCOMMAND

Function SQL_AVAILABLE_SQL_SERVER_NAME Global Integer iIndex Returns String
    Local String sName

    Get MertechInc_Pre_Size_String 80 to sName
    Call_Driver 0 SQLFLEX Function CALLDRV_ENUMERATE_SERVER CALLBACK 0 PASSING sName iIndex CALLDRV_ENUMERATE_SERVER_SERVER RESULT MertechInc_iRet

    Function_Return sName
End_Function

#Replace AvailableSQLServerName SQL_AVAILABLE_SQL_SERVER_NAME

//=============================================================================
/// @Name        SET_USE_ROWCOUNT_IN_TRANSACTION
/// @Description Turn on / off Row_Count for specified server
/// @Status      Deprecated
/// @Drivers     All
/// @VersionNote Last Revised: 2009-09-21 By Ian Smith
///
/// @Syntax SET_USE_ROWCOUNT_IN_TRANSACTION OF <Server> To <State>
/// @Param Server      Name of server to turn On / Off Row_Count
/// @Param State       TRUE = turn on Row_Count  FALSE = turn off Row_Count
///
/// @Comment This SHOULD ALWAYS BE TURNED ON
///
#COMMAND SET_USE_ROWCOUNT_IN_TRANSACTION "OF" R "TO" R .
    Set SQL_USE_ROWCOUNT_IN_TRANSACTIONS to !2 !4
#ENDCOMMAND

Procedure Set SQL_USE_ROWCOUNT_IN_TRANSACTIONS Global String sServer Integer iState
    DO_GETFILENUMBER_DRIVERNAME 0

    Call_Driver 0 MertechInc_DriverName Function CALLDRV_USE_ROWCOUNT_IN_TRANSACTIONS CALLBACK 0 PASSING sServer iState CALLDRV_VALUE_SET RESULT MertechInc_iRet
    If MertechInc_iRet EQ -1 INDICATE ERR True
End_Procedure

//IGS - commented out by a.n. Other
//#REPLACE UseRowCountInTransactions SQL_USE_ROWCOUNT_IN_TRANSACTIONS

//=============================================================================
/// @Name        GET_USE_ROWCOUNT_IN_TRANSACTION
/// @Description Gets the Row_Count setting for specified server
/// @Status      Deprecated
/// @Drivers     All
/// @VersionNote Last Revised: 2009-09-21 By Ian Smith
///
/// @Syntax GET_USE_ROWCOUNT_IN_TRANSACTION OF <Server> To <State>
/// @Param Server      Name of server to get Row_Count state of
/// @Param State       Variable to hold returned value
///
#COMMAND GET_USE_ROWCOUNT_IN_TRANSACTION "OF" R "TO" R .
    Get SQL_USE_ROWCOUNT_IN_TRANSACTIONS !2 to !4
#ENDCOMMAND

Function SQL_USE_ROWCOUNT_IN_TRANSACTIONS Global String sServer Returns Integer
    DO_GETFILENUMBER_DRIVERNAME 0

    Call_Driver 0 MertechInc_DriverName Function CALLDRV_USE_ROWCOUNT_IN_TRANSACTIONS CALLBACK 0 PASSING sServer MertechInc_Blank CALLDRV_VALUE_GET RESULT MertechInc_iRet

    Function_Return MertechInc_iRet
End_Function

#REPLACE UseRowCountInTransactions SQL_USE_ROWCOUNT_IN_TRANSACTIONS

//=============================================================================
/// @Name        SQL_SET_DATE_FORMAT
/// @Description Controls the date format of data returned through embedded SQL
/// @Status      Public
/// @Drivers     SQLFlex
/// @VersionNote Last Revised: 2009-09-21 By Ian Smith
///
/// @Syntax SQL_SET_DATE_FORMAT TO DATAFLEX | NATIVE
/// @Syntax Set SQL_USE_DATAFLEX_DATEFORMAT to [TRUE|FALSE]
///
#COMMAND SQL_SET_DATE_FORMAT TO "DATAFLEX""NATIVE"
    #IFSAME !2 DATAFLEX
        Set SQL_USE_DATAFLEX_DATEFORMAT to DFTRUE
    #ELSE
        Set SQL_USE_DATAFLEX_DATEFORMAT to DFFALSE
    #ENDIF
#ENDCOMMAND

Procedure Set SQL_USE_DATAFLEX_DATEFORMAT Global Integer iState
    DO_GETFILENUMBER_DRIVERNAME 0

    If MertechInc_DriverName eq SQLFlex Begin
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_USE_DFLEX_DATE_FORMAT CALLBACK 0 PASSING iState MertechInc_Blank CALLDRV_VALUE_SET RESULT MertechInc_iRet
        IF MertechInc_iRet EQ -1 INDICATE ERR TRUE
    End
End_Procedure

Function SQL_USE_DATAFLEX_DATEFORMAT Global Returns Integer
    DO_GETFILENUMBER_DRIVERNAME 0

    If MertechInc_DriverName eq SQLFlex Begin
        CALL_DRIVER 0 MertechInc_DriverName FUNCTION CALLDRV_USE_DFLEX_DATE_FORMAT CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank CALLDRV_VALUE_GET RESULT MertechInc_iRet
    End
    Else Move DFFALSE to MertechInc_iRet

    function_return MertechInc_iRet
End_Function

#Replace SqlUseDataflexDateFormat SQL_USE_DATAFLEX_DATEFORMAT

//=============================================================================
/// @Name        SET_FIELDS_NOT_NULL
/// @Description Controls the handling of when NULLs or blank/zero values
/// are stored in the SQL backend for NULLable columns.
///
/// Please see the Programmer's Guide chapter on NULL Handling for more information.
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-09-21 By Ian Smith
///
/// @Syntax SET_FIELDS_NOT_NULL TO [DFTRUE|DFFALSE]
/// @Syntax GET_FIELDS_NOT_NULL TO Var
///
/// @Comment *_NUT_NULL changes the setting for all data types.
/// @Comment Use *_NULL to change the setting for a specific data types.
///
/// @Usage SET_FIELDS_NOT_NULL TO [DFTRUE|DFFALSE]
/// @Usage Set SQL_FORCE_FIELDS_NOT_NULL TO TRUE
/// @Usage GET_FIELDS_NOT_NULL TO bNo_Nulls
/// @Usage Get SQL_FORCE_FIELDS_NOT_NULL TO bNo_Nulls
///
#COMMAND SET_FIELDS_NOT_NULL "TO" R .
   Set SQL_FORCE_FIELDS_NOT_NULL to !2
#ENDCOMMAND

Procedure Set SQL_FORCE_FIELDS_NOT_NULL Global Integer iState
    DO_GETFILENUMBER_DRIVERNAME 0

    If (MertechInc_FileNumber <> -1) Begin
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_FORCE_FIELDS_NOT_NULL CALLBACK 0 PASSING iState MertechInc_Blank CALLDRV_VALUE_SET RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
End_Procedure

#Replace SET_FORCE_FIELDS_NOT_NULL SET_FIELDS_NOT_NULL

#COMMAND GET_FIELDS_NOT_NULL "TO" R .
    Get SQL_FORCE_FIELDS_NOT_NULL to !2
#ENDCOMMAND

#Replace GET_FORCE_FIELDS_NOT_NULL GET_FIELDS_NOT_NULL

Function SQL_FORCE_FIELDS_NOT_NULL Global Returns Integer
    DO_GETFILENUMBER_DRIVERNAME 0

    If (MertechInc_FileNumber <> -1) Begin
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_FORCE_FIELDS_NOT_NULL CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank CALLDRV_VALUE_GET RESULT MertechInc_iRet
    End
    Else Move DFFALSE to MertechInc_iRet

    Function_Return MertechInc_iRet
End_Function

#Replace SqlForceFieldsNotNull SQL_FORCE_FIELDS_NOT_NULL

//=============================================================================
/// @Name        SET_FIELDS_NULL
/// @Description Controls the handling of when NULLs or blank/zero values
/// are stored in the SQL backend for NULLable columns.
///
/// Please see the Programmer's Guide chapter on NULL Handling for more information.
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-09-21 By Ian Smith
///
/// @Syntax SET_FIELDS_NULL [DF_ASCII|DF_BCD|DF_DATE] TO [DFTRUE|DFFALSE]
///
/// @Comment Use *_NULL to change the setting for a specific data types.
/// @Comment *_NUT_NULL changes the setting for all data types.
///
/// @Usage SET_FIELDS_NULL DF_ASCII to DFTRUE
///
#COMMAND SET_FIELDS_NULL "OF" R "TO" R .
    DO_GETFILENUMBER_DRIVERNAME 0

    If (MertechInc_FileNumber <> -1) Begin
        Move !2 to MertechInc_sArg1
        Move !4 to MertechInc_sArg2
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_FORCE_FIELDS_NULL CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_sArg2 CALLDRV_VALUE_SET RESULT MertechInc_iRet
        If MertechInc_iRet EQ -1 INDICATE ERR True
    End
#ENDCOMMAND

#Replace SET_FORCE_FIELDS_NULL SET_FIELDS_NULL

//=============================================================================
/// @Name        GET_FIELDS_NULL
/// @Description Controls the handling of when NULLs or blank/zero values
/// are stored in the SQL backend for NULLable columns.
///
/// Please see the Programmer's Guide chapter on NULL Handling for more information.
///
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2009-09-21 By Ian Smith
///
/// @Syntax GET_FIELDS_NULL [DF_ASCII|DF_BCD|DF_DATE] TO <Var>
///
/// @Comment Use *_NULL to change the setting for a specific data types.
/// @Comment *_NUT_NULL changes the setting for all data types.
/// some more comments
/// @Usage GET_FIELDS_NULL DF_ASCII to bAllow_NULL
///    some morer usage
///
#COMMAND GET_FIELDS_NULL "OF" R "TO" R .
    DO_GETFILENUMBER_DRIVERNAME 0

    If (MertechInc_FileNumber <> -1) Begin
        Move !2 to MertechInc_sArg1
        Call_Driver 0 MertechInc_DriverName Function CALLDRV_FORCE_FIELDS_NULL CALLBACK 0 PASSING MertechInc_sArg1 MertechInc_Blank CALLDRV_VALUE_GET RESULT MertechInc_iRet
        Move MertechInc_iRet to !4
    End
    Else Move DFFALSE to !4

#ENDCOMMAND

#Replace GET_FORCE_FIELDS_NULL GET_FIELDS_NULL

//=============================================================================
/// @Name        STRUCTURE_START_DYNAMIC
/// @Description Initializes the dynamic file restructure changes indicating to the driver that
///              an online restructuring is about to start
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2011-04-12 By Marcelo
///
/// @Syntax STRUCTURE_START_DYNAMIC OF <Table>
///
/// @Usage STRUCTURE_START_DYNAMIC OF Customer
///
#COMMAND STRUCTURE_START_DYNAMIC "OF" R .
    DO_GETFILENUMBER_DRIVERNAME !2

    If (MertechInc_FileNumber <> -1) Begin
        Call_Driver MertechInc_FileNumber MertechInc_DriverName Function CALLDRV_FILE_STRUCT_DYNAMIC_ONLINE CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 0 RESULT MertechInc_iRet
    End

#ENDCOMMAND

//=============================================================================
/// @Name        STRUCTURE_END_DYNAMIC
/// @Description Finishes the dynamic file restructure changes, refreshing the internal file structure updating
///              the file/fields/indexes information after a create_field or create_index is used outside a restructuring process
/// @Status      Public
/// @Drivers     All
/// @VersionNote Last Revised: 2011-04-12 By Marcelo
///
/// @Syntax STRUCTURE_END_DYNAMIC OF <Table>
///
/// @Usage STRUCTURE_END_DYNAMIC OF Customer
///
/// @Example
///     open "sql_drv:\\sqlserver2008\pubs*dbo*customer" as customer
///
///     integer iIndex iField
///
///     STRUCTURE_START_DYNAMIC of customer
///
///     Move 0 to iField
///     Create_Field customer.file_number At iField
///     Set_Attribute DF_FIELD_NAME   Of customer.file_number iField To "OVL"
///     Set_Attribute DF_FIELD_TYPE   Of customer.file_number iField To DF_OVERLAP
///     Set_Attribute DF_FIELD_OFFSET Of customer.file_number iField to 1
///     Set_Attribute DF_FIELD_LENGTH Of customer.file_number iField To 33
///
///     Move 0 to iIndex
///     Create_Index customer.file_number At iIndex
///
///     Set_Attribute DF_INDEX_NUMBER_SEGMENTS    Of customer.file_number iIndex To 2
///
///     Set_Attribute DF_INDEX_SEGMENT_FIELD      Of customer.file_number iIndex 1 To 12
///     Set_Attribute DF_INDEX_SEGMENT_FIELD      Of customer.file_number iIndex 2 To iField
///
///     STRUCTURE_END_DYNAMIC of customer
///
#COMMAND STRUCTURE_END_DYNAMIC "OF" R .
    DO_GETFILENUMBER_DRIVERNAME !2

    If (MertechInc_FileNumber <> -1) Begin
        Call_Driver MertechInc_FileNumber MertechInc_DriverName Function CALLDRV_FILE_STRUCT_DYNAMIC_ONLINE CALLBACK 0 PASSING MertechInc_Blank MertechInc_Blank 1 RESULT MertechInc_iRet
    End

#ENDCOMMAND



//=============================================================================
/// @Name        SQLSERVER_ATTACH_DB
/// @Description Attachs an MS SQL mdf to the current server instance. If
/// the passed database is already attached, no error is generated.
///
/// The SQLSERVER_ATTACH_DB command is intended for use with our new support
/// of Microsoft LocalDB's.  When using LocalDB's a common use case might be
/// to attach to a customer DB, do some work on it, and then detach this DB
/// and attach to a different DB.  This was possible using stored procedures,
/// but the code had some complexities that a developer need not worry about.
/// When you attach a database, you must pass the database name, along with
/// the path to an MDF file which contains the database.  Any associated LDF's
/// (log files) and NDF's (secondary data files) must be in the same folder.
///
/// If you call SQLSERVER_ATTACH_DB on a database that is already attached,
/// no error will be generated.  After you call SQLSERVER_ATTACH_DB, you
/// should call SET_DATABASE_NAME if you wish to make the attached database
/// the currently selected database.
///
/// SQLSERVER_ATTACH_DB will work on all supported version of SQL server.
///
/// @Status      Public
/// @Drivers     SQLFlex
/// @VersionNote Last Revised: 2012-06-19 Oliver Nelson
///
/// @Syntax SQLSERVER_ATTACH_DB <DBName> ON <MDFFilename>
///
/// @Usage SQLSERVER_ATTACH_DB "MTSample" ON "C:\Mertech\Data\SampleDb.mdf"
///
#COMMAND SQLSERVER_ATTACH_DB R "ON" R
    CALL_SQLSERVER_PROCEDURE "sp_databases"
    While (not(finderr))
        SQL_FETCH_NEXT_ROW into MertechInc_sWork
        If (Found and MertechInc_sWork = !1) Break
    Loop

    If (MertechInc_sWork <> !1) Begin
        SQL_SET_STMT to ("Create Database " + !1 + " on (filename='" + !3 + "') for attach")
        SQL_PREPARE_STMT
        SQL_EXECUTE_STMT
    End
#ENDCOMMAND

//=============================================================================
/// @Name        SQLSERVER_DETACH_DB
/// @Description The SQLSERVER_DETACH_DB command is intended for use with our
/// new support of Microsoft LocalDB's.  When using LocalDB's a common use
/// case might be to attach to a customer DB, do some work on it, and then
/// detach this DB and attach to a different DB.  This was possible using
/// stored procedures, but the code had some complexities that a developer
/// need not worry about.  A detach can only be done if the database passed
/// has no open connections.  As part of the detach process, the command
/// closes ALL open files (even those not associated with this database or
/// driver).
///
/// NOTE: SQLSERVER_DETACH_DB will often fail to execute if you are testing
/// your application from the studio.  This is because the studio itself
/// normally has open connections to the database.  If you test your
/// application outside of the studio and the studio is closed (and any
/// other application or tools that access this database are closed) you
/// can successfully detach the database.
///
/// @Status      Public
/// @Drivers     SQLFlex
/// @VersionNote Last Revised: 2012-06-19 Oliver Nelson
///
/// @Syntax SQLSERVER_DETACH_DB <DBName>
///
/// @Usage SQLSERVER_DETACH_DB "MTSample"
///
#COMMAND SQLSERVER_DETACH_DB R
    Close DF_ALL
    SQL_SET_STMT to "use master"
    SQL_PREPARE_STMT
    SQL_EXECUTE_STMT
    CALL_SQLSERVER_PROCEDURE "sp_detach_db" passing !1
#ENDCOMMAND


//=============================================================================
// End of Mertech.inc
//=============================================================================
