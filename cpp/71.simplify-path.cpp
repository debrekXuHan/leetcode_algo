/*
 * @lc app=leetcode id=71 lang=cpp
 *
 * [71] Simplify Path
 *
 * https://leetcode.com/problems/simplify-path/description/
 *
 * algorithms
 * Medium (31.10%)
 * Likes:    634
 * Dislikes: 1560
 * Total Accepted:    187.5K
 * Total Submissions: 602.9K
 * Testcase Example:  '"/home/"'
 *
 * Given an absolute path for a file (Unix-style), simplify it. Or in other
 * words, convert it to the canonical path.
 * 
 * In a UNIX-style file system, a period . refers to the current directory.
 * Furthermore, a double period .. moves the directory up a level. For more
 * information, see: Absolute path vs relative path in Linux/Unix
 * 
 * Note that the returned canonical path must always begin with a slash /, and
 * there must be only a single slash / between two directory names. The last
 * directory name (if it exists) must not end with a trailing /. Also, the
 * canonical path must be the shortest string representing the absolute
 * path.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: "/home/"
 * Output: "/home"
 * Explanation: Note that there is no trailing slash after the last directory
 * name.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "/../"
 * Output: "/"
 * Explanation: Going one level up from the root directory is a no-op, as the
 * root level is the highest level you can go.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: "/home//foo/"
 * Output: "/home/foo"
 * Explanation: In the canonical path, multiple consecutive slashes are
 * replaced by a single one.
 * 
 * 
 * Example 4:
 * 
 * 
 * Input: "/a/./b/../../c/"
 * Output: "/c"
 * 
 * 
 * Example 5:
 * 
 * 
 * Input: "/a/../../b/../c//.//"
 * Output: "/c"
 * 
 * 
 * Example 6:
 * 
 * 
 * Input: "/a//b////c/d//././/.."
 * Output: "/a/b/c"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dir_path = {};
        string temp = "";

        for (int i = 0; i < path.size(); i++) {
            if ('/' == path[i] && temp.empty()) {
                // the beginning for a dir
                if ('/' == path[i]) continue;
                temp.push_back(path[i]);
            }
            else if ('/' == path[i] && !temp.empty()) {
                // the end of a dir
                if ("." == temp) {
                    temp = "";
                    continue;
                }
                if (".." == temp) {
                    if (!dir_path.empty()) {
                        dir_path.pop_back();  // draw back a dir level
                    }
                    temp = "";
                    continue;
                }
                dir_path.push_back(temp);  // move forward a new dir level
                temp = "";
            }
            else if ('/' != path[i]) {
                temp.push_back(path[i]);
            }
            if (path.size() - 1 == i && !temp.empty()) {
                dir_path.push_back(temp);
            }
        }
        // deal with the last element in dir
        if (!dir_path.empty() && dir_path[dir_path.size() - 1] == ".") {
            dir_path.pop_back();
        }
        if (!dir_path.empty() && dir_path[dir_path.size() - 1] == "..") {
            dir_path.pop_back();
            if (!dir_path.empty()) dir_path.pop_back();
        }

        // generate the result string
        string result = "";
        for (int i = 0; i < dir_path.size(); i++) {
            result += '/';
            result += dir_path[i];
        }
        if (result.empty()) result = "/";
        return result;
    }
};
// @lc code=end

