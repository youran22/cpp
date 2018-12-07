package com.duicky;

import java.text.SimpleDateFormat;//时间类

import android.content.Context;
import android.util.Log;
import android.widget.Toast;//Toast类

/**
 * 使用：
 * 		LogUtils.printWithSystemOut(mStrMSg);
 * 		LogUtils.printWithSystemOut(mPerson1.toString())
 * 		LogUtils.printWithSystemOut("error");
 * 简单  Log 输出 集合
 * 
 * 		isSystemPrint等标签为是否输出信息的开关
 * 
 * @author luxiaofeng <454162034@qq.com>
 *
 */
public class LogUtils {
	
	public static Boolean isSystemPrint = true;//定义public static的Boolean变量；--是否系统打印
	public static Boolean isLogCatPrint = true;//是否LogCat打印
	public static Boolean isFilePrint = true;//是否文件打印？
	public static Boolean isToastMessage = true;//是否显示消息？
	public static SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");//定义并创建一个simpleDateFormat对象 ；
	
	//定义一个 用系统输出打印的方法 参数：标签，内容
	//此函数给下面的函数调用//这两个是重载函数？
	public static void printWithSystemOut(Boolean flag,String content) {
		if(flag) {
			//直接调用System.out.println函数;
			System.out.println(sdf.format(System.currentTimeMillis())+"   ----   "+content);//就是时间+内容
		}
	}	
	public static void printWithSystemOut(String content) {
		printWithSystemOut(isSystemPrint,content);
	}
	
	//打印LogCat的函数
	//此函数给下面的函数调用
	public static void printWithLogCat(Boolean flag,String filter,String content) {
		if(flag) {
			//直接调用Log.i（infor级别的函数）
			Log.i(filter,sdf.format(System.currentTimeMillis())+"   ----   "+content);
		}
	}	
	public static void printWithLogCat(String filter,String content) {
		printWithLogCat(isLogCatPrint,filter,content);
	}
	
	//定义发送弹出框打印的函数
	//此函数给下面的函数调用
	public static void toastMessage(Context mContext,Boolean flag,String strMsg) {
		if(flag) {
			//直接调用弹出框；
			Toast.makeText(mContext, strMsg, Toast.LENGTH_SHORT).show();
		}
	}	
	public static void toastMessage(Context mContext,String strMsg) {
		toastMessage(mContext,isToastMessage,strMsg);
	}
	
	public static void setLogOnOff(boolean flag) {
		isSystemPrint = flag;
		isLogCatPrint = flag;
		isFilePrint = flag;
		isToastMessage = flag;
	}
}
