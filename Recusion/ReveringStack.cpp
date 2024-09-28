void insert(stack<int> &st, int temp)
{
    if (st.empty())
    {
        st.push(temp);
        return;
    }

    int item = st.top();
    st.pop();
    insert(st, item);
    st.push(temp);
}

void reverse(stack<int> &st)
{
    if (st.size() == 1)
    {
        st.push(st.top());
        return;
    }
    int temp = st.top();
    st.pop();
    reverse(st);
    insert(st, temp);
}
void solve()
{
    int n;
    cin >> n;

    stack<int> st;
    f0r(i, n)
    {
        int num;
        cin >> num;
        st.push(num);
    }

    cout << "Print the stack before reversing: " << nl;
    stack<int> temp = st;
    while (!temp.empty())
    {
        cout << temp.top() << sp;
        temp.pop();
    }
    cout << nl;

    reverse(st);
    cout << "Print the stack after reversing: " << nl;
    while (!st.empty())
    {
        cout << st.top() << sp;
        st.pop();
    }
    cout << nl;
}
