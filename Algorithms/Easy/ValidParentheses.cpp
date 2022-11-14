bool isValid(std::string s)
{
    if (s.size() < 2)
        return false;

    std::stack<char> st;

    for (const char &ch : s )
    {
        if (ch == '{' || ch == '('|| ch == '[')
            st.push(ch);
        else
        {
            if (st.empty()) return false;

            if ((ch == '}' && st.top() == '{') ||
                (ch == ')' && st.top() == '(') ||
                (ch == ']' && st.top() == '['))
                    st.pop();
            else
                return false;
        }
    }

    return st.empty();
}
