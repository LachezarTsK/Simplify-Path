
import java.util.Deque;
import java.util.ArrayDeque;

public class Solution {

    private static final String DIRECTORY_SEPARATOR = "/";
    private static final String CURRENT_DIRECTORY = ".";
    private static final String DIRECTORY_UP_A_LEVEL = "..";

    public String simplifyPath(String path) {
        String[] elements = path.split(DIRECTORY_SEPARATOR);
        Deque<String> stackElements = new ArrayDeque<>();

        for (String element : elements) {
            if (element.equals(CURRENT_DIRECTORY) || element.isEmpty()) {
                continue;
            }
            if (element.equals(DIRECTORY_UP_A_LEVEL) && stackElements.isEmpty() == false) {
                stackElements.pop();

            } else if (element.equals(DIRECTORY_UP_A_LEVEL) == false) {
                stackElements.push(element);
            }
        }

        StringBuilder simplifiedCanonicalPath = new StringBuilder();
        assembleSimplifiedCanonicalPath(simplifiedCanonicalPath, stackElements);

        return simplifiedCanonicalPath.isEmpty() ? DIRECTORY_SEPARATOR : simplifiedCanonicalPath.toString();
    }

    public void assembleSimplifiedCanonicalPath(StringBuilder simplifiedCanonicalPath, Deque<String> stackElements) {
        while (!stackElements.isEmpty()) {
            simplifiedCanonicalPath.append(DIRECTORY_SEPARATOR);
            simplifiedCanonicalPath.append(stackElements.pollLast());
        }
    }
}
