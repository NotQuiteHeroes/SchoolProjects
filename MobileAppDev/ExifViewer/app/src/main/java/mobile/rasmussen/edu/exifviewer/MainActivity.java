package mobile.rasmussen.edu.exifviewer;

import android.content.Intent;
import android.database.Cursor;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.media.ExifInterface;
import android.net.Uri;
import android.os.Environment;
import android.provider.MediaStore;
import android.support.v4.content.FileProvider;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class MainActivity extends AppCompatActivity {

    ImageView photoViewer;
    TextView exifViewer;
    Button cameraButton;

    final int requestCode = 1;

    String currentPath;
    Uri photoUri;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        photoViewer = (ImageView) findViewById(R.id.photoViewer);
        exifViewer = (TextView) findViewById(R.id.exifViewer);
        cameraButton = (Button) findViewById(R.id.cameraButton);

        cameraButton.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View v)
            {
                takePhoto();
            }
        });
    }

    private void takePhoto()
    {
        Intent captureIntent = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);

        if(captureIntent.resolveActivity(getPackageManager()) != null)
        {
            File photo = null;
            try
            {
                photo = createImageFile();
            }
            catch(IOException e)
            {
                e.printStackTrace();
            }

            if(photo != null)
            {
                photoUri = FileProvider.getUriForFile(this, "mobile.rasmussen.edu.exifviewer", photo);
                captureIntent.putExtra(MediaStore.EXTRA_OUTPUT, photoUri);
                startActivityForResult(captureIntent, requestCode);
            }
        }
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if (this.requestCode == requestCode && resultCode == RESULT_OK)
        {
            try {
                Bitmap bitmap = MediaStore.Images.Media.getBitmap(this.getContentResolver(), photoUri);

                photoViewer.setImageBitmap(bitmap);
            }
            catch(IOException e)
            {
                e.printStackTrace();
            }

            try
            {
                ExifInterface exif = new ExifInterface(currentPath);
                displayExif(exif);
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
        }
    }

    private File createImageFile() throws IOException
    {
        String timeStamp = new SimpleDateFormat("yyyyMMdd_HHmmss").format(new Date());
        String fileName = "JPEG_" + timeStamp + "_";

        File storage = getExternalFilesDir(Environment.DIRECTORY_PICTURES);

        File image = File.createTempFile(fileName, ".jpg", storage);

        currentPath = image.getAbsolutePath();
        return image;
    }

    private void displayExif(ExifInterface exif)
    {
        String date = getTagString(ExifInterface.TAG_DATETIME, exif);
        String longitude = getTagString(ExifInterface.TAG_GPS_LONGITUDE_REF, exif);
        String latitude = getTagString(ExifInterface.TAG_GPS_LATITUDE_REF, exif);
        String length = getTagString(ExifInterface.TAG_IMAGE_LENGTH, exif);
        String width = getTagString(ExifInterface.TAG_IMAGE_WIDTH, exif);

        exifViewer.append(date);
        exifViewer.append(longitude);
        exifViewer.append(latitude);
        exifViewer.append(length);
        exifViewer.append(width);
    }

    private String getTagString(String tag, ExifInterface exif)
    {
        return(tag + " : " + exif.getAttribute(tag) + "\n");
    }

}
