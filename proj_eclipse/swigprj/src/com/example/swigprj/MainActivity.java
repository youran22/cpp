package com.example.swigprj;

//import com.duicky.LogUtils;
//import com.duicky.Person;
//import com.duicky.R;
//import com.duicky.Transmission;
//import com.duicky.MainActivity.MyOnClickListener;

import android.os.Bundle;
import android.app.Activity;
import android.content.Context;
import android.view.Menu;
import android.view.View;
import android.view.View.OnClickListener;//The method setOnClickListener(View.OnClickListener) in the type View is not applicable for the arguments 
import android.widget.Button;
import android.widget.TextView;

public class MainActivity extends Activity {

	//也就是你mk配置文件中的  LOCAL_MODULE    := NDK_06
	private Context mContext = null;
	private Transmission mTransmission = null;
	
	
	private Button btnString = null;
	private Button btnPerson = null;
	private TextView tvString = null;
	private TextView tvPerson = null;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
        mContext = this;
        mTransmission = new Transmission();
        initViews();
	}

	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		// Inflate the menu; this adds items to the action bar if it is present.
		getMenuInflater().inflate(R.menu.activity_main, menu);
		return true;
	}
	
	/////////////////////////////////////////////////////////////////////////////////////
	
	  /**
     * 初始化控件
     */
    private void initViews() {
    	btnString = (Button) findViewById(R.id.btn_string);
    	btnPerson = (Button) findViewById(R.id.btn_person);
		tvString = (TextView) findViewById(R.id.tv_string);
		tvPerson = (TextView) findViewById(R.id.tv_person);
		btnString.setOnClickListener(new MyOnClickListener());
		btnPerson.setOnClickListener(new MyOnClickListener());
	}
    
    class MyOnClickListener implements OnClickListener{

  		@Override
  		public void onClick(View v) {
  			switch(v.getId()) {
  				case R.id.btn_string:
  					transferString();
  					break;
  				case R.id.btn_person:
  					transferPerson();
  					break;
  			}
  		}
      }
    
    private void transferString() {
    	String mStrMSg = mTransmission.transferString(" This Message come from Java ");
    	LogUtils.printWithSystemOut(mStrMSg);
    	tvString.setText(mStrMSg);
	}

	private void transferPerson() {
		Person mPerson = new Person();
		mPerson.setAge(10);
		mPerson.setName("duicky");
		Person mPerson1 = (Person)mTransmission.transferPerson(mPerson);
		if(mPerson1 == null) {
			LogUtils.printWithSystemOut("error");
			tvPerson.setText("传递出现错误,请重试");
			return;
		}
		LogUtils.printWithSystemOut(mPerson1.toString());
		tvPerson.setText("Java --- > "+mPerson1.toString());
	}

}
