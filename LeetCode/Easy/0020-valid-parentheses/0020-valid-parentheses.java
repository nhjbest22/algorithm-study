class Solution {
    public boolean isValid(String s) {
        Deque<Character> stack = new ArrayDeque<>();
        int N = s.length();

        for(int i = 0; i < N; i++){
            char ch = s.charAt(i);

            if(ch == '(' || ch == '{' || ch == '['){
                stack.push(ch);
                continue;
            }

            if(stack.isEmpty()) return false;

            char ret = stack.pop();
            if(ch == ')' && ret != '(') return false;
            if(ch == '}' && ret != '{') return false;
            if(ch == ']' && ret != '[') return false;
        }

        return stack.size() > 0 ? false : true;        
    }
}