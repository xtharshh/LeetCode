class Solution {
public:
    string frequencySort(string s) {
    // Count the frequency of each character
        unordered_map<char, int> freqMap;
        for (char c : s) {
        freqMap[c]++;
        }//"e":2,"t":1, "r":1

    // Max-heap (priority queue) to sort by frequency
    priority_queue<pair<int, char>> maxHeap;
    for (auto& entry : freqMap) {
        maxHeap.push({entry.second, entry.first}); // Push {frequency, character}
    }//"e":2,"t":1, "r":1 this willl be pushed to {2:"e", 1:"t", 1:"r"}

    // Build the result string
    string result = "";
    while (!maxHeap.empty()) {
        auto [freq, ch] = maxHeap.top();
        maxHeap.pop();
        result += string(freq, ch); // Append character 'ch', 'freq' times
    }
    //freq=2, ch="e" -->top priority and poped, {freq=1, ch="t"} -->top and poped, then {freq=1, ch="r"} -->top and poped
    //ee will be there and then eet could be printed then eetr could be the output  

    return result;
}
};