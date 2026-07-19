class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, Integer> m = new HashMap<>();
        
        int idx = 0;
        var ans = new ArrayList<List<String>>();

        for(String str: strs){
            char[] c_str = str.toCharArray();
            Arrays.sort(c_str);

            String ret = new String(c_str);

            if(m.containsKey(ret)){
                ans.get(m.get(ret)).add(str);
                continue;
            }

            ans.add(new ArrayList<String>());
            ans.get(idx).add(str);
            
            m.put(ret, idx++);
        }

        return ans;
    }
}