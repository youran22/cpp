package com.duicky;

import java.text.SimpleDateFormat;//ʱ����

import android.content.Context;
import android.util.Log;
import android.widget.Toast;//Toast��

/**
 * ʹ�ã�
 * 		LogUtils.printWithSystemOut(mStrMSg);
 * 		LogUtils.printWithSystemOut(mPerson1.toString())
 * 		LogUtils.printWithSystemOut("error");
 * ��  Log ��� ����
 * 
 * 		isSystemPrint�ȱ�ǩΪ�Ƿ������Ϣ�Ŀ���
 * 
 * @author luxiaofeng <454162034@qq.com>
 *
 */
public class LogUtils {
	
	public static Boolean isSystemPrint = true;//����public static��Boolean������--�Ƿ�ϵͳ��ӡ
	public static Boolean isLogCatPrint = true;//�Ƿ�LogCat��ӡ
	public static Boolean isFilePrint = true;//�Ƿ��ļ���ӡ��
	public static Boolean isToastMessage = true;//�Ƿ���ʾ��Ϣ��
	public static SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");//���岢����һ��simpleDateFormat���� ��
	
	//����һ�� ��ϵͳ�����ӡ�ķ��� ��������ǩ������
	//�˺���������ĺ�������//�����������غ�����
	public static void printWithSystemOut(Boolean flag,String content) {
		if(flag) {
			//ֱ�ӵ���System.out.println����;
			System.out.println(sdf.format(System.currentTimeMillis())+"   ----   "+content);//����ʱ��+����
		}
	}	
	public static void printWithSystemOut(String content) {
		printWithSystemOut(isSystemPrint,content);
	}
	
	//��ӡLogCat�ĺ���
	//�˺���������ĺ�������
	public static void printWithLogCat(Boolean flag,String filter,String content) {
		if(flag) {
			//ֱ�ӵ���Log.i��infor����ĺ�����
			Log.i(filter,sdf.format(System.currentTimeMillis())+"   ----   "+content);
		}
	}	
	public static void printWithLogCat(String filter,String content) {
		printWithLogCat(isLogCatPrint,filter,content);
	}
	
	//���巢�͵������ӡ�ĺ���
	//�˺���������ĺ�������
	public static void toastMessage(Context mContext,Boolean flag,String strMsg) {
		if(flag) {
			//ֱ�ӵ��õ�����
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
