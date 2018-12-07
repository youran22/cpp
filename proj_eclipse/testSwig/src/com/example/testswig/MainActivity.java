package com.example.testswig;

import android.os.Bundle;
import android.app.Activity;
import android.view.Menu;

import android.widget.TextView;
import com.southgnss.*;
import com.southgnss.coordtransform.*;
import android.util.Log;

public class MainActivity extends Activity {
//	static {
//		System.loadLibrary("testSwig");
//	}
	static String Tag = "--------";
	private testSwigJNI cSwig = new testSwigJNI();
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);		
		String str = null;
		
//		testSwigJNI cSwig = new testSwigJNI();
		
//		double r1=0.0,alfa=0.0, x=0.0,y=0.0,z=0.0;
//		long b=123,l=124,h=125;
//		testSwigJNI.XYZToBLH(r1, alfa, x, y, z, b, l, h);
//		str = String.format("%d %d %d \r\n", b, l, h);
		
		
		double r=0.0, alfa=0.0,x=0.1,y=0.2,z=0.3;
//		double[] b={0.0},l={0.0},h={0.0};//
		double b[]={0.0}, l[]={0.0}, h[]={0.0};//这个可以；
//		testSwigJNI.XYZToBLH(r,alfa,x, y, z, b,l,h);
//		testSwig.Add(b, l);
		testSwigJNI.Add(b,l);		
		double b1=b[0],l1=l[0],h1=h[0];		
		str = String.format("%f %f %f \r\n",b1,l1,h1);
		
//		String strName = new String();
		StringBuffer strBuf = new StringBuffer();
		byte[] name = new byte[512];
		testSwigJNI.GetName(name, 12);
		
		String strName = null;
		try {
			strName = new String(name, "GBK");//GB2312  ISO-8859-1
		}catch(Exception e)
		{
			e.printStackTrace();
		}
		str += String.format("%s \r\n", strName);
		
		TextView tv = new TextView(this);
		tv.setText(str);
		setContentView(tv);
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.activity_main, menu);
		return true;
	}

}
