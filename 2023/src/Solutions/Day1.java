package Solutions;

import java.io.*;
import java.net.URL;
import java.util.*;

public class Day1 {

    private URL dataPath = getClass().getResource("../Data/day1.txt");
    private List<String> numberList = new ArrayList<String>();

    public Day1() {
        numberList.add("one");
        numberList.add("two");
        numberList.add("three");
        numberList.add("four");
        numberList.add("five");
        numberList.add("six");
        numberList.add("seven");
        numberList.add("eight");
        numberList.add("nine");
    }


    public int Part1() {
        int output = 0;

        try {
            Scanner scanner = new Scanner(new File(dataPath.getPath()));

            while (scanner.hasNextLine()) {
                String currLine = scanner.nextLine();

                // Get all number.
                List<Character> numberList = new ArrayList<Character>();
                for (int x = 0; x < currLine.length(); ++x) {
                    if (Character.isDigit(currLine.charAt(x))) {
                        numberList.add(currLine.charAt(x));
                    }
                }

                if (numberList.size() == 0) {
                    continue;
                } else if (numberList.size() > 1) {
                    String outputString = "" + numberList.get(0) + numberList.get(numberList.size() - 1);
                    output += Integer.parseInt(outputString);
                } else {
                    String outputString = "" + numberList.get(0) + numberList.get(0);
                    output += Integer.parseInt(outputString);
                }

            }

            scanner.close();

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        return output;
    }

    public int Part2() {
        int output = 0;

        try {
            Scanner scanner = new Scanner(new File(dataPath.getPath()));

            while (scanner.hasNextLine()) {
                String currLine = scanner.nextLine();

                // Get all number.
                List<Character> numberList = new ArrayList<Character>();
                for (int x = 0; x < currLine.length(); ++x) {
                    if (Character.isDigit(currLine.charAt(x))) {

                        // Check if word number exists at beginning of string.
                        if (numberList.size() == 0) {
                            String substring = currLine.substring(0, x);
                            char characterToNumber = substringIncludesNumber(substring);
                            if(characterToNumber != Character.MIN_VALUE){
                                numberList.add(characterToNumber);
                            }
                        }

                        numberList.add(currLine.charAt(x));
                    }
                }

                // Check if word number exists at the end of string.
                for (int x = currLine.length() - 1; x > 0; --x) {
                    if (Character.isDigit(currLine.charAt(x))) {

                        // Check if word number exists at beginning of string.
                        if (numberList.size() == 0) {
                            String substring = currLine.substring(0, x);
                            char characterToNumber = substringIncludesNumber(substring);
                            if(characterToNumber != Character.MIN_VALUE){
                                numberList.add(characterToNumber);
                            }
                        }

                        numberList.add(currLine.charAt(x));
                    }
                }

                if (numberList.size() == 0) {
                    continue;
                } else if (numberList.size() > 1) {
                    String outputString = "" + numberList.get(0) + numberList.get(numberList.size() - 1);
                    output += Integer.parseInt(outputString);
                } else {
                    String outputString = "" + numberList.get(0) + numberList.get(0);
                    output += Integer.parseInt(outputString);
                }

            }

            scanner.close();

        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        return output;
    }

    private char substringIncludesNumber(String inString) {

        for (int x = 0; x < numberList.size(); ++x) {
            if (inString.indexOf(numberList.get(x)) > 0) {
                return (char) (x + 1);
            }
        }

        return Character.MIN_VALUE;
    }


}