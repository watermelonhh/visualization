#ifndef BASEDEFINE_H
#define BASEDEFINE_H

#define HEAD_LENGTH	13
#define CHANNEL_NUM	9
#define END_LENGTH	3
#define MAX_BEACON_NUMS 8
#define PI 3.14159265358979323
#define RAY_PACKET_LEN 110
#define POSFIER_PACKET_LEN 178
#define LINENUMBER   100
#define MAX_PATHNAME_LEN  260
#define ROWX 5000
#define ROWY 5000
#define REF_FLAG_NUM 20
#define DOWNSECONDS 5
#include <qstring.h>

typedef struct _SIX_DOUBLE_ARRAY
{
    char Value1[8];
    char Value2[8];
    char Value3[8];
    char Value4[8];
    char Value5[8];
    char Value6[8];
} SIX_DOUBLE_ARRAY;
typedef struct _NINE_DOUBLE_ARRAY
{
    char Value1[8];
    char Value2[8];
    char Value3[8];
    char Value4[8];
    char Value5[8];
    char Value6[8];
    char Value7[8];
    char Value8[8];
    char Value9[8];
} NINE_DOUBLE_ARRAY;
typedef struct _CONTROL_STA_PACKET
{
    unsigned char PacketID[HEAD_LENGTH];
    char start;
    unsigned char PacketID2[END_LENGTH];
} CONTROL_STA_PACKET;

typedef struct _CONTROL_BEA_PACKET
{   //=====ÐÅ±ê¿ØÖÆÅäÖÃ°ü=====//
    unsigned char       PacketID[HEAD_LENGTH];
    char                BeaCode[30];
    char 				PacketID2[END_LENGTH];
} CONTROL_BEA_PACKET;

typedef struct _CONTROL_CMD_PACKET
{	   //======²ÎÊýÃüÁî¿ØÖÆ°ü======//
    unsigned char PacketID[HEAD_LENGTH];
    char Magnify;			 //ÔöÒæ
    char PowerLevel;		 //¹¦ÂÊµµ
    char LocaMode;
    char WorkMode;			 //¹¤×÷Ä£Ê½
    char CalculateMode;	 	//¼ÆËãÄ£Ê½
    char SetDepth[8];		 //¸ø¶¨Éî¶ÈÄ£Ê½Éè¶¨µÄÉî¶È
    char CompassNum;		 //ÂÞ¾­Ñ¡Ôñ
    char retain[2];            //Ô¤Áô2×Ö½Ú
    unsigned char PacketID2[END_LENGTH];
} CONTROL_CMD_PACKET;

typedef struct _CONTROL_COM_PACKET
{		  //======´®¿ÚÅäÖÃ°ü======//
    unsigned char PacketID[HEAD_LENGTH];
    char GPSPortNumber;	    //GPS´®¿ÚºÅ3-8
    char GPSPortBaudRate[4];   //²¨ÌØÂÊ	======longÐÍÊý¾Ý======£¿£¿£¿
    char GPSPortDataBits;  //Êý¾ÝÎ»Êý Ä¬ÈÏÖµ£º7Î»£¬ÓÐÐ§Öµ£º5£¬6£¬7£¬8Î»
    char GPSPortStopBits;  //Í£Ö¹Î»Êý Ä¬ÈÏÖµ£º1Í£Ö¹Î»£¬ÓÐÐ§Öµ£º1or2Í£Ö¹Î»
    char GPSPortParity;    //Ð£Ñé·½Ê½£º0-²»Ð£Ñé£¬1-ÆæÐ£Ñé£¬2-Å¼Ð£Ñé
    char GPSStyle;         //Êý¾Ý¸ñÊ½

    char Compass2PortNumber;	//ÂÞ¾­2´®¿ÚºÅ3-8
    char  Compass2PortBaudRate[4];   //²¨ÌØÂÊ
    char Compass2PortDataBits;  //Êý¾ÝÎ»Êý Ä¬ÈÏÖµ£º7Î»£¬ÓÐÐ§Öµ£º5£¬6£¬7£¬8Î»
    char Compass2PortStopBits;  //Í£Ö¹Î»Êý Ä¬ÈÏÖµ£º1Í£Ö¹Î»£¬ÓÐÐ§Öµ£º1or2Í£Ö¹Î»
    char Compass2PortParity;    //Ð£Ñé·½Ê½£º0-²»Ð£Ñé£¬1-ÆæÐ£Ñé£¬2-Å¼Ð£Ñé
    char Compass2Style;         //Êý¾Ý¸ñÊ½

    char VRUPortNumber;	//×ËÌ¬´«¸ÐÆ÷´®¿ÚºÅ3-8
    char VRUPortBaudRate[4];   //²¨ÌØÂÊ
    char VRUPortDataBits;  //Êý¾ÝÎ»Êý Ä¬ÈÏÖµ£º7Î»£¬ÓÐÐ§Öµ£º5£¬6£¬7£¬8Î»
    char VRUPortStopBits;  //Í£Ö¹Î»Êý Ä¬ÈÏÖµ£º1Í£Ö¹Î»£¬ÓÐÐ§Öµ£º1or2Í£Ö¹Î»
    char VRUPortParity;    //Ð£Ñé·½Ê½£º0-²»Ð£Ñé£¬1-ÆæÐ£Ñé£¬2-Å¼Ð£Ñé
    char VRUStyle;         //Êý¾Ý¸ñÊ½

    unsigned char PacketID2[END_LENGTH];
} CONTROL_COM_PACKET;


typedef struct _CONTROL_CAL_PACKET
{		 //======Ð£×¼²ÎÊý°ü======//
    unsigned char       PacketID[HEAD_LENGTH];
    SIX_DOUBLE_ARRAY 	ParameterWrap;
    char				SoundSpeed[8];
    unsigned char PacketID2[END_LENGTH];
} CONTROL_CAL_PACKET;

typedef struct _CONTROL_CHA_PACKET
{
    unsigned char PacketID[HEAD_LENGTH];
    char input_signal;			 //ÊäÈëÐÅºÅÔ´Ñ¡Ôñ
    char output_chanel_num;		//Êä³öÍ¨µÀ¸öÊýÉèÖÃ
    char chanel_info[3];		  //Êä³öÍ¨µÀÐÅÏ¢0,1,2ÅäÖÃ
    char periodic_time[2];		 // Ñ­»·´ÎÊýÉèÖÃ
    unsigned char  PacketID2[END_LENGTH];
} CONTROL_CHA_PACKET;

typedef struct _CONTROL_CMU_PACKET
{
    unsigned char       PacketID[HEAD_LENGTH];
    char status_flag;
    char R_check[8];
    char Depth_check[8];
    char invalid_check[8];
    unsigned char PacketID2[END_LENGTH];
} CONTROL_CMU_PACKET;

typedef struct _CONTROL_SYN_PACKET
{
    unsigned char PacketID[HEAD_LENGTH];
    char TriggerMode;		 //Í¬²½Ä£Ê½
    char PortNum;			 //Í¬²½ÊäÈë¶Ë¿Ú
    char SynPeriod;		 	//Í¬²½ÖÜÆÚ
    unsigned char PacketID2[END_LENGTH];
} CONTROL_SYN_PACKET;

typedef struct _CONTROL_DET_PACKET
{   //=====¼ì²â²ÎÊýÅäÖÃ°ü=====//
    unsigned char       PacketID[HEAD_LENGTH];
    char                AbsNoiseThreshold[4];   // ¾ø¶ÔÔëÉùÃÅÏÞ  µ¥Î»£º±¶
    char                AbsNoiseThreshold_1[4];
    char                RelNoiseThreshold[4];   // Ïà¶ÔÔëÉùÃÅÏÞ  µ¥Î»£º±¶
    char                MinWidthThreshold[4];   // ×îÐ¡Âö¿íÃÅÏÞ
    char                MaxWidthThreshold[4];   // ×î´óÂö¿íÃÅÏÞ
    char                NoiseEstCycle[4];		// ÔëÉù¹À¼ÆÖÜÆÚ  µ¥Î»£ºms
    char				AngelThreshold[8];		// ½Ç¶ÈÅÐ¾öÃÅÏÞ  µ¥Î»£º¡ã
    char 				PacketID2[END_LENGTH];
} CONTROL_DET_PACKET;

typedef struct _CONTROL_COR_PACKET
{		 //======ÏµÍ³ÐÞÕý²ÎÊý°ü======//
    unsigned char       PacketID[HEAD_LENGTH];
    NINE_DOUBLE_ARRAY 	SystemParameter;	// ÏµÍ³ÐÞÕý²ÎÊý£ºµÚÒ»Î»ÎªÕóÔª¼ä¾à ºó°ËÎ»Îª8Â·Ê±ÑÓÐÞÕýÖµ
    unsigned char       PacketID2[END_LENGTH];
} CONTROL_COR_PACKET;

typedef struct _CONTROL_GTIME_PACKET
{
    unsigned char PacketID[HEAD_LENGTH];
    char port[2];			 //¶Ë¿Ú
    char period[3];		//ÖÜÆÚ
    char hour[3];		  //Ê±
    char minute[3];		 // ·Ö
    char seconds[3];		 // Ãë
    unsigned char  PacketID2[END_LENGTH];
} CONTROL_GTIME_PACKET;

typedef struct _CONTROL_MULTI_PACKET
{   //=====ÐÅ±ê¿ØÖÆÅäÖÃ°ü=====//
    unsigned char       PacketID[HEAD_LENGTH];
    char                MultiCmmd[2];
    char 				PacketID2[END_LENGTH];
} CONTROL_MULTI_PACKET;
typedef struct _CONTROL_SIG_PACKET
{   //=====信号体制参数配置包=====//
    unsigned char       PacketID[HEAD_LENGTH];
    char                SendSignalNo[4];        // 发射信号编号
    char                SendSignalFreq[8];      // 发射信号频率  单位：kHz
    char                ReceiveSignalNo[4];     // 接收信号编号
    char                ReceiveSignalFreq[8];   // 接收信号频率  单位：kHz
    char                TAT[8];		            // 转发时延  单位：ms°
    char 				PacketID2[END_LENGTH];
} CONTROL_SIG_PACKET;
typedef struct  _CONTROL_MULTISIG_PACKET
{ //信标参数
    int     Validflag;
    int     Workmod;
    int     Calmod;
    double  Depthnum;
    int     Cifcode;      // ·¢ÉäÐÅºÅ±àºÅ
    double  Ciffreq;      // ·¢ÉäÐÅºÅÆµÂÊ  µ¥Î»£ºkHz
    int 	Irfcode;      // ½ÓÊÕÐÅºÅ±àºÅ
    double  Irffreq;      // ½ÓÊÕÐÅºÅÆµÂÊ  µ¥Î»£ºkHz
    double  Irftat;		  // ×ª·¢Ê±ÑÓ  µ¥Î»£ºms
} CONTROL_MULTISIG_PACKET;

typedef struct USBL_R232_MODULE
{
    unsigned char TransferBuffer[2048];
    CONTROL_STA_PACKET StartPacket;
    CONTROL_BEA_PACKET BEAPacket;
    CONTROL_CMD_PACKET CommandPacket;
    CONTROL_COM_PACKET ComPacket;
    CONTROL_CAL_PACKET CalPacket;
    CONTROL_CHA_PACKET ChaPacket;
    CONTROL_CMU_PACKET CmuPacket;
    CONTROL_SYN_PACKET SynPacket;
    CONTROL_DET_PACKET DetPacket;
    CONTROL_COR_PACKET CorPacket;
    CONTROL_GTIME_PACKET GpsTimePacket;
    CONTROL_MULTI_PACKET MultiPacket;
    //CONTROL_MULTISIG_PACKET MultisigPacket;
    char Sig8Packet[700];
    char svppacket[300];
    char accpacket[300];
    char firpacket[300];
    char girpacket[300];
    char arraypacket[300];
    char bpspacket[300];
    char lblcalPacket[700];
    char arrxpacket[300];
} R232_MODULE;

typedef struct _R232_CONFIG_PARAM
{
    int DataPortNumber;
    long DataPortBaudRate;//波特率
    int DataPortParity;//校验方式：0-不校验，1-奇校验，2-偶校验
    int DataPortDataBits;//数据位数 默认值：7位，有效值：5，6，7，8位
    int DataPortStopBits;//停止位数 默认值：1停止位，有效值：1or2停止位
    int ControlPortNumber;
    long ControlPortBaudRate;//波特率
    int ControlPortParity;//校验方式：0-不校验，1-奇校验，2-偶校验
    int ControlPortDataBits;//数据位数 默认值：7位，有效值：5，6，7，8位
    int ControlPortStopBits;//停止位数 默认值：1停止位，有效值：1or2停止位
} R232_CONFIG_PARAM;

typedef struct  _CONTROL_SVP_PACKET
{
    unsigned char PacketID[13];
    int     validflag;
    unsigned char PacketID2[3];
}CONTROL_SVP_PACKET;

typedef struct  _CONTROL_ACC_PACKET
{
    unsigned char PacketID[13];
    int     validflag;
    double coef_a;
    double coef_b;
    double coef_c;
    double coef_d;
    unsigned char PacketID2[3];
}CONTROL_ACC_PACKET;

typedef struct  _CONTROL_FIR_PACKET
{
    unsigned char PacketID[13];
    int     validflag;
    double coef_a;
    double coef_b;
    double coef_c;
    double coef_d;
    unsigned char PacketID2[3];
}CONTROL_FIR_PACKET;

typedef struct  _CONTROL_GIR_PACKET
{
    unsigned char PacketID[13];
    int     validflag;
    double coef_a;
    unsigned char PacketID2[3];
}CONTROL_GIR_PACKET;

typedef struct  _CONTROL_ARRYX_PACKET
{
    unsigned char PacketID[13];
    double arryx_1;
    double arryx_2;
    double arryx_3;
    double arryx_4;
    double arryx_5;
    double arryx_6;
    double arryx_7;
    double arryx_8;
    double arryx_9;
    double arryx_10;
    int arraytype;
    int gpsswitch;
    unsigned char PacketID2[3];

}CONTROL_ARRYX_PACKET;

/**********************数据处理模块***************************/
typedef struct _FOUR_FLOAT_ARRAY {
    char Value1[4];
    char Value2[4];
    char Value3[4];
    char Value4[4];
} FOUR_FLOAT_ARRAY;

typedef struct _THREE_DOUBLE_ARRAY {
    char Value1[8];
    char Value2[8];
    char Value3[8];
} THREE_DOUBLE_ARRAY;

typedef struct three_DOUBLE_ARRAY {     //2025/3/21
    double Value1;
    double Value2;
    double Value3;
} three_DOUBLE_ARRAY;

typedef struct _THREE_DOUBLE_ARRAY_QT {
    QString Value1;
    QString Value2;
    QString Value3;
}THREE_DOUBLE_ARRAY_QT;

typedef struct _FOUR_DOUBLE_ARRAY {
    char Value1[8];
    char Value2[8];
    char Value3[8];
    char Value4[8];
} FOUR_DOUBLE_ARRAY;


typedef struct _NINE_SHORT_ARRAY {
    char Value1[2];
    char Value2[2];
    char Value3[2];
    char Value4[2];
    char Value5[2];
    char Value6[2];
    char Value7[2];
    char Value8[2];
    char Value9[2];
} NINE_SHORT_ARRAY;

typedef struct _TWO_DOUBLE_ARRAY {
    char Value1[8];
    char Value2[8];
} TWO_DOUBLE_ARRAY;

typedef struct _NINE_INT_ARRAY {
    char Value1[4];
    char Value2[4];
    char Value3[4];
    char Value4[4];
    char Value5[4];
    char Value6[4];
    char Value7[4];
    char Value8[4];
    char Value9[4];
} NINE_INT_ARRAY;

typedef struct _UPLOAD_COMPLEX_PACKAGE {
    unsigned char 		pcomplex_packet[HEAD_LENGTH];		//±êÖ¾Í·
    unsigned char 		BeaconIndex;				//ÐÅ±ê±àºÅ
    unsigned char 		Status;						//标志位 只有1个字节 如果为0，则这个数据无效
    unsigned char 		Sign[2]; 					//showÃ»Ê¹ÓÃ ±êÖ¾Î»£¨´¦Àí»úÓÃ£©
    unsigned char		ChanIsValid[CHANNEL_NUM];	//¸÷Í¨µÀÊý¾ÝÊÇ·ñÓÐÐ§   ?short »¹ÊÇchar
    NINE_INT_ARRAY      PeakNum;
    NINE_INT_ARRAY      PeakValue;					 //j0704int
    NINE_INT_ARRAY      Noise;						//ÔëÉù  j0627noise
    NINE_INT_ARRAY      NoisePeak;					//ÔëÉù°üÂçÖµ LZ 20121109
    NINE_DOUBLE_ARRAY 	TimeDelayArrayPos;			//ÈýÖÖÊ±ÑÓ
    NINE_DOUBLE_ARRAY   TimeDelayArrayZero;         //无法解包，加上了这行
    NINE_DOUBLE_ARRAY 	TimeDelayArrayNeg;
    NINE_DOUBLE_ARRAY 	TimeDelayArray;
    TWO_DOUBLE_ARRAY 	Fangcha;  					//·½²î			 ?
    char 				Depth[8];					//Ñ¹Á¦´«¸ÐÆ÷Éî¶È
    FOUR_DOUBLE_ARRAY 	GpsArray;  					//时间 经度 纬度 高程
    char				NSEW[2];					//ÄÏ±±Î³£¨N£¬S£©£¬¶«Î÷¾­£¨E£¬W£©
    THREE_DOUBLE_ARRAY 	CompassArray1;				//Heading, Pitch, Roll
    THREE_DOUBLE_ARRAY 	CompassArray2; 				//ÁíÒ»Ì×ÂÞ¾­
    THREE_DOUBLE_ARRAY 	BoardCoordinateArray;		//´¬×ø±ê
    THREE_DOUBLE_ARRAY 	ArrayCoordinateArray;		//»ùÕó×ø±ê
    THREE_DOUBLE_ARRAY 	UTMCoordinateArray; 		//´óµØ×ø±ê //
    char				R[8];						//Ð±¾à
    char				Magnify;					//ÔöÒæ	   //j0622magnify
    unsigned char		PowerLevel;					//showÃ»Ê¹ÓÃ
    unsigned char 		WorkMode;					//showÃ»Ê¹ÓÃ
    unsigned char 		CalculateMode; 				//showÃ»Ê¹ÓÃ
    unsigned char		CompassNum;					//ÂÞ¾­Ñ¡Ôñ00060108
    SIX_DOUBLE_ARRAY 	ParameterWrap;				//showÃ»Ê¹ÓÃ
    char				SoundSpeed[8];				//showÃ»Ê¹ÓÃ
    char                AbsNoiseThreshold[4];       // ¾ø¶ÔÔëÉùÃÅÏÞ  µ¥Î»£º±¶  LZ 20121109
    char                RelNoiseThreshold[4];       // Ïà¶ÔÔëÉùÃÅÏÞ  µ¥Î»£º±¶  LZ 20121109
    char                MinWidthThreshold[4];       // ×îÐ¡Âö¿íÃÅÏÞ  LZ 20121109
    char                MaxWidthThreshold[4];       // ×î´óÂö¿íÃÅÏÞ  LZ 20121109
    char                TimeEstCycle[4];		    // Ê±ÑÓ¹À¼ÆÖÜÆÚ  µ¥Î»£ºms  LZ 20121109
    NINE_DOUBLE_ARRAY 	SystemParameter;	        // ÏµÍ³ÐÞÕý²ÎÊý£ºµÚÒ»Î»ÎªÕóÔª¼ä¾à ºó°ËÎ»Îª8Â·Ê±ÑÓÐÞÕýÖµ  LZ 20121109
    char                AbsSNR[4];                  // ¾ø¶ÔÔëÉùÃÅÏÞ  µ¥Î»£º±¶  LZ 20121109
    char                RelSNR[4];                  // Ïà¶ÔÔëÉùÃÅÏÞ  µ¥Î»£º±¶  LZ 20121109
    char                ActualWidth[4];             // ×îÐ¡Âö¿íÃÅÏÞ  LZ 20121109
    char				AngelThreshold[8];		    // ½Ç¶ÈÅÐ¾öÃÅÏÞ  µ¥Î»£º¡ã LZ 20121109
    unsigned char		PacketID2[END_LENGTH];
} UPLOAD_COMPLEX_PACKET;

typedef struct USBL_COORDINATE {
    double X;
    double Y;
    double Z;
} _3D_COORDINATE;

typedef struct USBL_VELOCITY {
    double Vx;
    double Vy;
    double Vz;
} _3D_VELOCITY; //3DËÙ¶È

typedef struct USBL_VELOCITY1 {
    double Vx;
    double Vy;
    double Vz;
    double Vd;
} _4D_VELOCITY; //4DËÙ¶È

typedef struct _RAY_FIX_MODULE {
    int cal_flag;	  //ÄÄÖÖ¼ÆËã·½Ê½
    double detaX[3];
    double angel[3];
    //double T_odd[4];
    double ray_heading;
    double ray_pitch;
    double ray_roll;
    _3D_COORDINATE Xg;
    _3D_COORDINATE Xj;   //»ùÕó×ø±êÏµ×ø±ê
    double C_Aver; // Æ½¾ùÉùËÙ
    double R_Aver; // Ð±¾à
    double Rjs[3][3];
    char *p_buffer;
    double *c1;
    double *c2;
    int readindex;
    int rayfix_flag;   //ÅÐ¶Ï¶ÁÈ¡ÉùËÙÎÄ¼þÊý¾ÝÊÇ·ñÍê³É
    int start_ray_flag;		//ÅÐ¶ÏÊÇ·ñ¿ªÆô¡°ÉùËÙÐÞÕý¡±°´Å¥
    _3D_COORDINATE RayBeaconUtm; //¼ÆËãÍê µÄ´óµØ×ø±ê
    _3D_COORDINATE RayBeaconUtm_E;//Equal_raytraceËã·¨µÄ½á¹û
    _3D_COORDINATE RayBeaconArray; //ÉùÏßÐÞÕý1 µÄ»ùÕó×ø±ê
    _3D_COORDINATE RayBeaconArray_E;
    int valid_flag;  //ÅÐ¶ÏµÚÒ»ÖÖ¼ÆËã·½Ê½µÄ×´Ì¬±êÖ¾
    int valid_flag_E;//EqualËã·¨µÄ×´Ì¬±êÖ¾
    double Depth_Target; //Ä¿±êÉî¶È
    double Speed_Final; //Ä¿±ê´¦ÉùËÙ
    double Speed_Origin; // »ùÕóÈëË®´¦ÉùËÙ
    double depth_array;		//»ùÕóÈëË®Éî¶È
    int file_line_num;		//ÉùËÙÎÄ¼þÓÐ¶àÉÙÐÐ
    double Ray_Angel;       //ÉùÏßÂÓÉä½Ç(²âÁ¿)
    bool Ray_CalFlag;	   // Ê±¼äÏàµÈÉùÏß¸ú×Ù¼ÆËã±êÖ¾
    bool Ray_CalFlag_E;	   // µÈÐ§ÆÊÃæÉùÏß¸ú×Ù¼ÆËã±êÖ¾
} RAY_FIX_MODULE;

typedef struct _NAVI_MODULE {
    _3D_COORDINATE AverNavi;  //ÉùÏß¸ú×Ùµ¼º½½á¹û
    _3D_COORDINATE RayNavi;  //ÉùÏß¸ú×Ùµ¼º½½á¹û
    _3D_COORDINATE RayNavi_E; //µÈÐ§ÆÊÃæµ¼º½½á¹û
    _3D_COORDINATE NaviRef;  //µ¼º½²Î¿¼ÐÅ±êÎ»ÖÃ
    bool Navi_ShowFlag; //µ¼º½ÐÅÏ¢ÏÔÊ¾±íÊ¾
} NAVI_MODULE;

typedef struct _KALMAN_MODULE {
    _3D_COORDINATE PointToFilter;   // ´ýÂË²¨²ÎÊý£¨¾ßÌåÊÇÊ²Ã´´ý¶¨£©
    _3D_COORDINATE PointFiltered;   // ÂË²¨ºó²ÎÊý£¨¾ßÌåÊÇÊ²Ã´´ý¶¨£©

    double ObserveNoise; // ¹Û²âÔëÉù
    double SystemNoise;  // ÏµÍ³ÔëÉù
    double SampleCycle;  // ²ÉÑùÖÜÆÚ
    int TargetStyle;	    // Ä¿±êÀàÐÍ
    bool Kal_CalFlag;    // ¿¨¶ûÂüÂË²¨¼ÆËã±êÖ¾
} KALMAN_MODULE;

typedef struct _POSFILTER_MODULE {
    int start_posfilter_flag;
    int T;
    int Num;
    double Value[4];
    double K_static[2];
    double K_move[2];
    double L_standard;
    _4D_VELOCITY v_real;
    _4D_VELOCITY v_new;
    _3D_COORDINATE PosFilterBeaconUtm; //
} POSFILTER_MODULE;

typedef struct USBL_COMPASS {
    double Heading;
    double Pitch;
    double Roll;
    double Heave;
} COMPASS_INFO;

typedef struct USBL_GPS {
    double GpsTime;
    double Longitude;
    double Latitude;
    double Altitude;
    char   NSEW[2];
}
GPS_INFO;

typedef struct USBL_BOARD_INFO {
    _3D_COORDINATE UtmCoordinate;
    GPS_INFO Gps;
    COMPASS_INFO Compass;
    COMPASS_INFO Compass1;
    COMPASS_INFO Compass2;
    unsigned char CompassNum;
} BOARD_INFO;

typedef struct USBL_BEACON_INFO {
    _3D_COORDINATE UtmCoordinate;
    _3D_COORDINATE ArrayCoordinate;
    _3D_COORDINATE PosFIR_UtmCoordinate;
    GPS_INFO Gps;
    GPS_INFO Gps_Pos_Filter;
    _4D_VELOCITY v_real;
    _4D_VELOCITY v_new;
    double R;
    double HeadingAngle;
    double PitchAngle;
    double XAngle;
    double YAngle;
    double Depth;
    double r;
    int valid_flag;
} BEACON_INFO;

typedef struct USBL_TARGET_INFO {
    _3D_COORDINATE UtmCoordinate;
    _3D_COORDINATE ArrayCoordinate;
    GPS_INFO Gps;
    int valid_flag;
    double Ray_Angel;
    double R;
    double HeadingAngle;
    double PitchAngle;
    double XAngle;
    double YAngle;
    double Depth;
    double r;
} TARGET_INFO;

typedef struct USBL_SIGNAL_INFO {
    unsigned char ChanIsValid[CHANNEL_NUM];
    double TimeDelayArray[9];
    int PeakValue[9];
    double PeakValueshow[9];
    double Var[2];
    unsigned char StatusAccuracy;
    int Noise[9];
    double  Noiseshow[9];
    int NoisePeak[9];
    char Magnify;
} SIGNAL_INFO;

typedef struct _USBL_SHOW_DATA { //显示链表
    BOARD_INFO BoardInfo;
    BEACON_INFO BeaconInfo;
    SIGNAL_INFO SignalInfo;
    int ShowDataIsValid;
    struct _USBL_SHOW_DATA *pNext;
} USBL_SHOW_DATA;

typedef struct USBL_DATA_CHAIN { //数据链
    USBL_SHOW_DATA *pStart;
    USBL_SHOW_DATA *pWrite;
    USBL_SHOW_DATA *pRead;
    int NumInChain;
} DATA_CHAIN;

#endif // BASEDEFINE_H
