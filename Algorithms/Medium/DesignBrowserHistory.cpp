/*
1472. Design Browser History

You have a browser of one tab where you start on the homepage and you
can visit another url, get back in the history number of steps or move
forward in the history number of steps.

Implement the BrowserHistory class:

BrowserHistory(string homepage) Initializes the object with the homepage of the browser.

void visit(string url) Visits url from the current page. It clears up all the forward history.

string back(int steps) Move steps back in history. If you can only return x steps in the
history and steps > x, you will return only x steps. Return the current url after moving
back in history at most steps.

string forward(int steps) Move steps forward in history. If you can only forward x steps
in the history and steps > x, you will forward only x steps. Return the current url after
forwarding in history at most steps.
*/

class BrowserHistory {
public:
    BrowserHistory(std::string homepage)
    : m_pos(0)
    , m_steps()
    {
        m_steps.push_back(homepage);
    }
    
    void visit(std::string url) 
    {
        while (m_pos != m_steps.size() - 1) m_steps.pop_back();
        m_steps.push_back(url);
        m_pos = m_steps.size() - 1;    
    }
    
    std::string back(int steps) 
    {
        m_pos -= steps;

        if (m_pos < 0)
        {
            m_pos = 0;
            return m_steps.front();
        }

        return m_steps[m_pos];
    }
    
    std::string forward(int steps) 
    {
        m_pos += steps;

        if (m_pos > m_steps.size() - 1)
        {
            m_pos = m_steps.size() - 1;
            return m_steps.back();
        }

        return m_steps[m_pos];
    }

private:
    int m_pos;
    std::vector<std::string> m_steps;

};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
