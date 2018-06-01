package com.eckstein.paige.directions;

import android.os.AsyncTask;
import android.text.Html;
import android.view.View;
import android.widget.ProgressBar;

import org.w3c.dom.Document;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

import java.io.IOException;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.URL;
import java.util.ArrayList;

import javax.xml.parsers.DocumentBuilder;
import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;

public class AsyncTaskRunner extends AsyncTask<String, Integer, ArrayList<String>> {
    String source;
    String destination;
    String api;
    String address;
    public AsyncResponse delegate = null;
    ProgressBar bar;

    AsyncTaskRunner(AsyncResponse asyncResponse, String source, String destination, String api)
    {
        this.delegate = asyncResponse;
        this.source = source;
        this.destination = destination;
        this.api = api;
        generateAddress();
    }

    private void generateAddress()
    {
        String sourceString = getSourceString();
        String destString = getDestString();

        address = "https://maps.googleapis.com/maps/api/directions/xml?"+sourceString+"&"+destString+"&key="+api;
        System.out.println(address);

    }

    private String getSourceString()
    {
        String[] splitSource = source.trim().split("\\s+");
        StringBuilder sb1 = new StringBuilder();
        sb1.append("origin=");
        for(String str : splitSource)
        {
            sb1.append(str);
            sb1.append("+");
        }
        sb1.setLength(sb1.length() - 1);

        return (new String(sb1));
    }

    private String getDestString()
    {
        String[] splitDest = destination.trim().split("\\s+");

        StringBuilder sb2 = new StringBuilder();
        sb2.append("destination=");
        for(String str : splitDest)
        {
            sb2.append(str);
            sb2.append("+");
        }
        sb2.setLength(sb2.length() - 1);
        return (new String(sb2));
    }

    private ArrayList<String> getDirections(Document doc)
    {
        System.out.println("In getDirections");
        NodeList nl1, nl2;
        ArrayList<String> directions = new ArrayList<String>();
        nl1 = doc.getElementsByTagName("step");
        if(nl1.getLength() > 0)
        {
            for(int i = 0; i < nl1.getLength(); i++)
            {
                Node node1 = nl1.item(i);
                System.out.println(nl1.item(i));
                nl2 = node1.getChildNodes();
                Node directionNode = nl2.item(getNodeIndex(nl2, "html_instructions"));
                String instruction = directionNode.getTextContent();
                directions.add(String.valueOf(Html.fromHtml(instruction)));
            }
        }

        return directions;
    }

    private int getNodeIndex(NodeList nodeList, String nodeName) {
        for(int i = 0 ; i < nodeList.getLength() ; i++) {
            if(nodeList.item(i).getNodeName().equals(nodeName))
                return i;
        }
        return -1;
    }

    public void setProgressBar(ProgressBar progressBar)
    {
        this.bar = progressBar;
        bar.setVisibility(View.VISIBLE);
    }

    @Override
    protected ArrayList<String> doInBackground(String... params)
    {
        for(int i = 0; i < 100; i++)
        {
            try {
                Thread.sleep(100);
                publishProgress(i);
            } catch (InterruptedException e)
            {
                e.printStackTrace();
            }
        }
        HttpURLConnection con = null;
        URL url = null;
        ArrayList<String> directions = null;
        try{
            url = new URL(address);
            con = (HttpURLConnection) url.openConnection();
            con.setRequestMethod("GET");
            con.setDoOutput(true);
            con.setDoInput(true);
            con.connect();
            DocumentBuilderFactory dbf = DocumentBuilderFactory.newInstance();
            DocumentBuilder db = dbf.newDocumentBuilder();
            System.out.println(con.getInputStream());
            Document doc = (Document) db.parse(con.getInputStream());


            directions = getDirections(doc);
        } catch (MalformedURLException e)
        {
            e.printStackTrace();
        } catch (IOException e)
        {
            e.printStackTrace();
        } catch (ParserConfigurationException e)
        {
            e.printStackTrace();
        } catch (SAXException e)
        {
            e.printStackTrace();
        }

        return directions;
    }

    @Override
    protected void onPostExecute(ArrayList<String> result)
    {
        bar.setVisibility(View.GONE);
        delegate.processFinish(result);
    }


    @Override
    protected void onProgressUpdate(Integer... ints)
    {
        if(this.bar != null)
        {
            bar.setProgress(ints[0]);
        }
    }
}
