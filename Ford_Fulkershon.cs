using System;
using System.Collections;
using System.Collections.Generic;

class edge
{
    public int u, v, w;
    public edge(int a, int b, int c)
    {
        this.u = a;
        this.v = b;
        this.w = c;
    }
}

public class Fordfulk
{
    static private int s = 0, t = 5;
    static public int f = 0;
    static private void max_flow(int[,] m)
    {
        bool[] visited = new bool[6];
        visited[s] = true;
        List<edge> al = new List<edge>();
        max_flow_util(s, t, m, visited, al);
    }
    static private void max_flow_util(int s, int t, int[,] m, bool[] v, List<edge> al)
    {
        v[s] = true;
        if (s == t)
        {
            int min = Int16.MaxValue;
            for (int i = 0; i < al.Count; i++)
            {
                if (min > al[i].w)
                {
                    min = al[i].w;
                }
            }
            for (int i = 0; i < al.Count; i++)
            {
                al[i].w -= min;
                m[al[i].u, al[i].v] = al[i].w;
                if (al[i].w == 0)
                    m[al[i].u, al[i].v] = -1;
                m[al[i].v, al[i].u] = min;
            }
            f += min;
            al.Clear();
        }
        for (int i = 0; i < 6; i++)
        {
            if (m[s, i] != -1 && !v[i])
            {
                al.Add(new edge(s, i, m[s, i]));
                max_flow_util(i, t, m, v, al);
            }
        }
        if (al.Count > 0)
            al.RemoveAt(al.Count - 1);
        v[s] = false;
    }
    static public void Main()
    {
        int[,] adj = new int[6, 6] { { -1, 13, 16, -1, -1, -1 }, { -1, -1, 4, 14, -1, -1 }, { -1, -1, -1, -1, 12, -1 }, { -1, -1, -1, -1, 7, 4 }, { -1, 9, -1, -1, -1, 20 }, { -1, -1, -1, -1, -1, -1 } };
        int[,] flow = new int[6, 6];
        max_flow(adj);
        Console.WriteLine("Flow: " + f);
    }
}
