package com.example.prjtest00;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;


//���log
import android.util.Log;
import android.app.AlertDialog;
import android.widget.TextView;//�������޷�ʶ������⣬Ҫ���¹���jdk������ļ����ɽ����
import android.content.Context;




import com.apress.swig.Unix;
//import com.apress.swig.UnixJNI;
//import com.apress.swig.Unix;



public class MainActivity extends Activity {
	
	static String Tag = "PrjTest00-MainActivity";
	
	static {
		try {
			System.loadLibrary("JniPrj");
		}catch (Exception e){
			e.printStackTrace();
			Log.d(Tag, "LoadLibrary error");
		}
		Log.d(Tag, "LoadLibrary success");
	}
	


	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		//�������ô���
//		Object object = null;
//		object.toString();
		setContentView(R.layout.activity_main);	
		
		String str = null;//���ֱ��str+= ���nullҲ��ʾ��ǰ�棿

		//jni program example 1
//		Log.d(Tag, "before invocation func stringFromJni");
//		str = stringFromJNI();
//		str += "\n";		
//		Log.d("after invocation func stringFromJni :%s", str);
		
		//swig program example 
//		Unix unix = new Unix();
//		long lUid = unix.getuid();//UnixJNI ��Unix ������ʲô����//UnixJNI.getuid() ��ֱ�ӵ��ò��У�
//		Log.d(Tag, "after invocation func getuid");		
//		str += String.format("Hello My Angle %c Uid:%d\n", ':', lUid);
		
		
		str = String.format("û����\n");		
		TextView tv = new TextView(this);
		tv.setText(str);
		setContentView(tv);
//		new AlertDialog.Builder(this).setMessage(str).show();
		
		//jni_NDK_07 program example
//		context = this;
//        mTransmission = new Transmission();
//        initViews();
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.activity_main, menu);
		return true;
	}
	
	//���native����:����ʵ�֣�Ϊjavah����׼����
	//��û��static������
//	public native String stringFromJNI();
	


}
