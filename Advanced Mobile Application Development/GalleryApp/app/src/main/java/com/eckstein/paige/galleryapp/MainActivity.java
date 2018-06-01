package com.eckstein.paige.galleryapp;

import android.Manifest;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.net.Uri;
import android.os.Bundle;
import android.provider.MediaStore;
import android.support.design.widget.FloatingActionButton;
import android.support.v7.app.AppCompatActivity;
import android.text.SpannableString;
import android.text.Spanned;
import android.text.method.LinkMovementMethod;
import android.text.style.ClickableSpan;
import android.util.DisplayMetrics;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;
import android.widget.TextView;

import java.io.File;
import java.util.ArrayList;
import java.util.List;


public class MainActivity extends AppCompatActivity {

    //Camera fragment
    static final int REQUEST_IMAGE_CAPTURE = 1;
    TextView imageList;
    boolean isTablet;
    ImageView imageView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        requestPermissions(new String[]{Manifest.permission.READ_EXTERNAL_STORAGE},
               100);

        imageList = findViewById(R.id.photoList);
        //Camera button
        FloatingActionButton cameraButton = findViewById(R.id.cameraButton);
        cameraButton.setOnClickListener(new View.OnClickListener()
        {
            @Override
            public void onClick(View v)
            {
                launchCamera(v);
            }
        });

        isTablet = isTablet();
        //Disable Button if device has no camera
        if(!hasCamera()){
            cameraButton.setEnabled(false);
        }

    }

    //Check for camera capability
    private boolean hasCamera(){
        return getPackageManager().hasSystemFeature(PackageManager.FEATURE_CAMERA_ANY);
    }

    //Launch Camera
    public void launchCamera(View view){
        Intent intent = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
        //Take Picture
        startActivityForResult(intent, REQUEST_IMAGE_CAPTURE);
    }

    //return picture taken by camera
    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {

        if(requestCode == REQUEST_IMAGE_CAPTURE && resultCode == RESULT_OK){
            updatePhotoList();
        }
    }

    public void updatePhotoList()
    {
        List<String> imageNames = getCameraImages(this);
        imageList.setText("");
        for(String img : imageNames)
        {
            final String image = img;
            SpannableString ss = new SpannableString(img);
            ClickableSpan span = new ClickableSpan() {
                @Override
                public void onClick(View textView)
                {
                    if(!isTablet) {
                        Intent intent = new Intent(MainActivity.this, ImageViewActivity.class);
                        intent.putExtra("path", image);
                        startActivity(intent);
                    }
                    else
                    {
                        imageView = findViewById(R.id.cameraImageView);
                        File imgFile = new File(image);
                        if(imgFile.exists())
                        {
                            Bitmap bitmap = BitmapFactory.decodeFile(imgFile.getAbsolutePath());
                            imageView.setImageBitmap(bitmap);
                        }
                    }
                }
            };
            ss.setSpan(span, 0, img.length(), Spanned.SPAN_EXCLUSIVE_EXCLUSIVE);
            imageList.append(ss);
            imageList.setMovementMethod(LinkMovementMethod.getInstance());
        }

    }

    public static List<String> getCameraImages(Context context) {
        final String[] projection = { MediaStore.Images.Media.DATA };
        final Cursor cursor = context.getContentResolver().query(MediaStore.Images.Media.EXTERNAL_CONTENT_URI,
                projection,
                null,
                null,
                null);
        ArrayList<String> result = new ArrayList<>(cursor.getCount());
        if (cursor.moveToFirst()) {
            final int dataColumn = cursor.getColumnIndexOrThrow(MediaStore.Images.Media.DATA);
            do {
                final String data = cursor.getString(dataColumn);
                result.add(data);
            } while (cursor.moveToNext());
        }
        cursor.close();
        return result;
    }

    public boolean isTablet() {
        try {
            // Compute screen size
            DisplayMetrics dm = this.getResources().getDisplayMetrics();
            float screenWidth = dm.widthPixels / dm.xdpi;
            float screenHeight = dm.heightPixels / dm.ydpi;
            double size = Math.sqrt(Math.pow(screenWidth, 2) +
                    Math.pow(screenHeight, 2));

            // Tablet devices should have a screen size greater than 6 inches
            return size >= 6;
        } catch (Throwable t) {
            System.out.println("Cannot determine screen size.");
            return false;
        }
    }
}
