#include <iostream>
#include <vector>

int main()
{
    std::string texture;

    int caseNo = 1;
    while (true)
    {
        std::cin >> texture;
        if (texture == "END")
        {
            return 0;
        }

        std::cout << caseNo << " ";
        caseNo++;

        if (texture.size() == 1)
        {
            std::cout << "EVEN" << '\n';
        }

        else
        {

            int distance;
            for (int i = 1; i < texture.size(); i++)
            {
                if (texture[i] == '*')
                {
                    distance = i;
                    break;
                }
            }

            std::vector<int> delimIdx {};
            bool evenDelims = true;
            int lastStarDistance = 0;

            

            for (int i = 1; i < texture.size(); i++)
            {
                if (texture[i] == '*')
                {
                    if (lastStarDistance != distance-1)
                    {
                        evenDelims = false;
                        break;
                    }

                    lastStarDistance = 0;
                    delimIdx.push_back(i);  
                }

                else
                {
                    lastStarDistance++;
                }
            }

            bool correctFiller = true;
            if (evenDelims)
            {
                for (int i = 0; i < delimIdx.size()-1; i++)
                {
                    int delim = delimIdx[i];
                    int nextDelim = delimIdx[i+1];
                    for (int j = delim+1; j < nextDelim; j++)
                    {
                        if (texture[j] != '.')
                        {
                            correctFiller = false;
                            break;
                        }
                    }
                }
            }

            if (!evenDelims || !correctFiller)
            {
                std::cout << "NOT EVEN" << '\n';
            }

            else
            {
                std::cout << "EVEN" << '\n';
            }
        }
    }
}
