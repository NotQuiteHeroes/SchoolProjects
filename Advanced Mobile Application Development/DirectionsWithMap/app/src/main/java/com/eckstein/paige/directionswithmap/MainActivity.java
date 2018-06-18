package com.eckstein.paige.directionswithmap;

import android.content.Context;
import android.graphics.Color;
import android.support.v4.app.FragmentActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.view.inputmethod.InputMethodManager;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ProgressBar;
import android.widget.TextView;

import com.google.android.gms.maps.CameraUpdateFactory;
import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.OnMapReadyCallback;
import com.google.android.gms.maps.SupportMapFragment;
import com.google.android.gms.maps.model.LatLng;
import com.google.android.gms.maps.model.PolylineOptions;
import com.google.maps.DirectionsApi;
import com.google.maps.DirectionsApiRequest;
import com.google.maps.GeoApiContext;
import com.google.maps.model.DirectionsLeg;
import com.google.maps.model.DirectionsResult;
import com.google.maps.model.DirectionsRoute;
import com.google.maps.model.DirectionsStep;
import com.google.maps.model.EncodedPolyline;

import java.util.ArrayList;
import java.util.List;

public class MainActivity extends FragmentActivity  implements OnMapReadyCallback{

    EditText source;
    EditText destination;
    Button getDirections;
    TextView directionsView;
    ProgressBar progressBar;
    GoogleMap map;
    SupportMapFragment mapFragment;

    String sourceText = "", destinationText = "";
    String api;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        source = findViewById(R.id.source);
        destination = findViewById(R.id.destination);
        getDirections = findViewById(R.id.directionsButton);
        directionsView = findViewById(R.id.directionsDisplay);
        progressBar = findViewById(R.id.progressBar);
        progressBar.setVisibility(View.GONE);
        mapFragment = (SupportMapFragment) getSupportFragmentManager().findFragmentById(R.id.mapFragment);

        api = getResources().getString(R.string.google_maps_key);

        getDirections.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                InputMethodManager inputManager = (InputMethodManager)
                        getSystemService(Context.INPUT_METHOD_SERVICE);

                inputManager.hideSoftInputFromWindow(getCurrentFocus().getWindowToken(),
                        InputMethodManager.HIDE_NOT_ALWAYS);
                sourceText = source.getText().toString();
                destinationText = destination.getText().toString();
                drawMap();
                AsyncTaskRunner asyncTask = new AsyncTaskRunner(new AsyncResponse()
                {
                    @Override
                    public void processFinish(ArrayList<String> directions)
                    {
                        for(String direction : directions)
                        {
                            directionsView.append(direction + "\n");
                        }
                        //drawMap();
                    }
                }, sourceText, destinationText, api);
                asyncTask.setProgressBar(progressBar);
                asyncTask.execute("");
            }
        });

    }

    public void drawMap()
    {
        mapFragment.getMapAsync(this);
    }

    @Override
    public void onMapReady(GoogleMap gMap)
    {
        map = gMap;
        List<LatLng> path = new ArrayList<>();

        GeoApiContext context = new GeoApiContext.Builder().apiKey(api).build();
        DirectionsApiRequest req = DirectionsApi.getDirections(context, sourceText, destinationText);
        try
        {
            DirectionsResult result = req.await();

            if(result.routes != null && result.routes.length > 0)
            {
                DirectionsRoute route = result.routes[0];

                if(route.legs != null)
                {
                    for(int i = 0; i < route.legs.length; i++)
                    {
                        DirectionsLeg leg = route.legs[i];
                        if(leg.steps != null)
                        {
                            for(int j = 0; j < leg.steps.length; j++)
                            {
                                DirectionsStep step = leg.steps[j];
                                if(step.steps != null && step.steps.length > 0)
                                {
                                    for(int k = 0; k < step.steps.length; k++)
                                    {
                                        DirectionsStep step1 = step.steps[k];
                                        EncodedPolyline points1 = step1.polyline;
                                        if(points1 != null)
                                        {
                                            List<com.google.maps.model.LatLng> coords1 = points1.decodePath();
                                            for(com.google.maps.model.LatLng coord1 : coords1)
                                            {
                                                path.add(new LatLng(coord1.lat, coord1.lng));
                                            }
                                        }
                                    }
                                } else {
                                    EncodedPolyline points = step.polyline;
                                    if(points != null)
                                    {
                                        List<com.google.maps.model.LatLng> coords = points.decodePath();
                                        for(com.google.maps.model.LatLng coord : coords)
                                        {
                                            path.add(new LatLng(coord.lat, coord.lng));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }  catch (Exception ex)
        {
            Log.e("MAP_READY: ", ex.getLocalizedMessage());
        }

        if(path.size() > 0)
        {
            PolylineOptions opts = new PolylineOptions().addAll(path).color(Color.CYAN).width(10);
            map.addPolyline(opts);
        }

        map.getUiSettings().setZoomControlsEnabled(true);
        map.moveCamera(CameraUpdateFactory.newLatLngZoom(path.get(0), 15));

    }
}


