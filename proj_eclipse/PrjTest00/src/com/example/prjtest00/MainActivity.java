package com.example.prjtest00;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;


//添加log
import android.util.Log;
import android.app.AlertDialog;
import android.widget.TextView;//会遇到无法识别的问题，要重新关联jdk里面的文件即可解决？
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
		//故意设置错误：
//		Object object = null;
//		object.toString();
		setContentView(R.layout.activity_main);	
		
		String str = null;//如果直接str+= 会把null也显示在前面？

		//jni program example 1
//		Log.d(Tag, "before invocation func stringFromJni");
//		str = stringFromJNI();
//		str += "\n";		
//		Log.d("after invocation func stringFromJni :%s", str);
		
		//swig program example 
//		Unix unix = new Unix();
//		long lUid = unix.getuid();//UnixJNI 跟Unix 调用有什么区别？//UnixJNI.getuid() ：直接调用不行？
//		Log.d(Tag, "after invocation func getuid");		
//		str += String.format("Hello My Angle %c Uid:%d\n", ':', lUid);
		
		
		str = String.format("没问题\n");		
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
	
	//添加native函数:无需实现；为javah命令准备；
	//有没有static的区别：
//	public native String stringFromJNI();
	


}
