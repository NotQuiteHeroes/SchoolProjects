package mobile.rasmussen.edu.simplecalculator;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;


public class MainActivity extends AppCompatActivity {

    private EditText textField;

    Button button0, button1, button2, button3, button4, button5, button6, button7, button8, button9;
    Button buttonAdd, buttonSubtract, buttonDivide, buttonMultiply, buttonClear, buttonDecimal, buttonEquals;

    float operand1, operand2;

    boolean add, subtract, multiply, divide;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //this.textField = (TextView) findViewById(R.id.textField);

        button0 = (Button) findViewById(R.id.buttonZero);
        button0.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                textField.setText(getString(R.string.stringZero));
            }
        });
        button1 = (Button) findViewById(R.id.buttonOne);
        button1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                textField.setText(getString(R.string.stringOne));
            }
        });
        button2 = (Button) findViewById(R.id.buttonTwo);
        button2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                textField.setText(getString(R.string.stringTwo));
            }
        });
        button3 = (Button) findViewById(R.id.buttonThree);
        button3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                textField.setText(getString(R.string.stringThree));
            }
        });
        button4 = (Button) findViewById(R.id.buttonFour);
        button4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                textField.setText(getString(R.string.stringFour));
            }
        });
        button5 = (Button) findViewById(R.id.buttonFive);
        button5.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                textField.setText(getString(R.string.stringFive));
            }
        });
        button6 = (Button) findViewById(R.id.buttonSix);
        button6.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                textField.setText(getString(R.string.stringSix));
            }
        });
        button7 = (Button) findViewById(R.id.buttonSeven);
        button7.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                textField.setText(getString(R.string.stringSeven));
            }
        });
        button8 = (Button) findViewById(R.id.buttonEight);
        button8.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                textField.setText(getString(R.string.stringEight));
            }
        });
        button9 = (Button) findViewById(R.id.buttonNine);
        button9.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                textField.setText(getString(R.string.stringNine));
            }
        });

        buttonAdd = (Button) findViewById(R.id.buttonAdd);
        buttonAdd.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (textField == null) {
                    textField.setText("");
                } else {
                    operand1 = Float.parseFloat(textField.getText() + "");
                    add = true;
                    textField.setText(null);
                }
            }
        });
        buttonSubtract = (Button) findViewById(R.id.buttonSubtract);
        buttonSubtract.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (textField == null) {
                    textField.setText("");
                } else {
                    operand1 = Float.parseFloat(textField.getText() + "");
                    subtract = true;
                    textField.setText(null);
                }
            }
        });
        buttonDivide = (Button) findViewById(R.id.buttonDivide);
        buttonDivide.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (textField == null) {
                    textField.setText("");
                } else {
                    operand1 = Float.parseFloat(textField.getText() + "");
                    divide = true;
                    textField.setText(null);
                }
            }
        });
        buttonMultiply = (Button) findViewById(R.id.buttonMultiply);
        buttonMultiply.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (textField == null) {
                    textField.setText("");
                } else {
                    operand1 = Float.parseFloat(textField.getText() + "");
                    multiply = true;
                    textField.setText(null);
                }
            }
        });

        buttonDecimal = (Button) findViewById(R.id.buttonDecimal);
        buttonDecimal.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                textField.setText(getString(R.string.stringDecimal));
            }
        });
        buttonClear = (Button) findViewById(R.id.buttonClear);
        buttonClear.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                textField.setText("");
            }
        });
        buttonEquals = (Button) findViewById(R.id.buttonEquals);
        buttonEquals.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (textField == null) {
                    textField.setText("");
                } else {
                    operand2 = Float.parseFloat(textField.getText() + "");
                    textField.setText(null);
                }

                if (add) {
                    textField.setText(String.valueOf(operand1 + operand2));
                    add = false;
                }

                if (subtract) {
                    textField.setText(String.valueOf(operand1 - operand2));
                    subtract = false;
                }

                if (multiply) {
                    textField.setText(String.valueOf(operand1 * operand2));
                    multiply = false;
                }

                if (divide) {
                    textField.setText(String.valueOf(operand1 / operand2));
                    divide = false;
                }
            }
        });
        
        textField = (EditText) findViewById(R.id.textField);

    }
}



