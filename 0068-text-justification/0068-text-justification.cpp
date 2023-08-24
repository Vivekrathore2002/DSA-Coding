// https://www.youtube.com/watch?v=tb1tHpinFrc
class Solution {
private:
    void processLineWithKWords(vector<string>& currLine, int currWidth, int maxWidth, vector<string>& result) {
        int whiteSpaces = maxWidth - currWidth;
        int evenSpaces = whiteSpaces / (currLine.size() - 1);
        int unevenSpaces = whiteSpaces % (currLine.size() - 1);

        int word = 0;

        // Distribute spaces evenly
        while (word < currLine.size() - 1) {
            int spaces = 0;
            while (spaces < evenSpaces) {
                currLine[word] += " ";
                spaces += 1;
            }
            word += 1;
        }

        // Left must have extra spaces
        word = 0;
        while (unevenSpaces > 0) {
            currLine[word] += " ";
            word += 1;
            unevenSpaces -= 1;
        }

        string tempRes = "";
        for (int k = 0; k < currLine.size(); k++) {
            if (k == 0) {
                tempRes += currLine[k];
            } else {
                tempRes = tempRes + " " + currLine[k];
            }
        }

        result.push_back(tempRes);
    }

    void processLineWithOneWord(vector<string>& currLine, int currWidth, int maxWidth, vector<string>& result) {
        int whiteSpaces = maxWidth - currWidth;
        string tempRes = currLine[0];
        while (whiteSpaces > 0) {
            tempRes += " ";
            whiteSpaces -= 1;
        }
        result.push_back(tempRes);
    }

    void processLastLine(vector<string>& currLine, int currWidth, int maxWidth, vector<string>& result) {
        int whiteSpaces = maxWidth - currWidth;
        string tempRes = currLine[0];
        if (currLine.size() > 1) {
            for (int i = 1; i < currLine.size(); i++) {
                tempRes += " " + currLine[i];
            }
        }
        while (whiteSpaces > 0) {
            tempRes += " ";
            whiteSpaces -= 1;
        }
        result.push_back(tempRes);
    }
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        vector<string> currLine;
        int currWidth = 0;
        for (int i = 0; i < words.size(); i++) {
            // Calculate currWidth and see if this line can accomodate currWord
            int value = currLine.size() == 0 ? words[i].length() : (currWidth + words[i].length() + 1);

            if (value <= maxWidth) {
                currLine.push_back(words[i]);
                currWidth = value;
            } else {

                if (currLine.size() > 1) {
                    processLineWithKWords(currLine, currWidth, maxWidth, result);
                } else {
                    processLineWithOneWord(currLine, currWidth, maxWidth, result);
                }
                currLine.clear();
                currLine.push_back(words[i]);
                currWidth = words[i].length();
            }
        }
        processLastLine(currLine, currWidth, maxWidth, result);
        return result;
    }
};