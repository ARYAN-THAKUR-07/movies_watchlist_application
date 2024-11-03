#include <iostream>
#include <vector>
#include <string>

class MovieWatchlist {
public:
    void addMovie(const std::string& movie) {
        watchlist.push_back(movie);
        std::cout << "Added: " << movie << std::endl;
    }

    void viewMovies() const {
        if (watchlist.empty()) {
            std::cout << "Your watchlist is empty." << std::endl;
            return;
        }
        std::cout << "Your Watchlist:" << std::endl;
        for (size_t i = 0; i < watchlist.size(); ++i) {
            std::cout << i + 1 << ". " << watchlist[i] << std::endl;
        }
    }

    void removeMovie(int index) {
        if (index < 1 || index > watchlist.size()) {
            std::cout << "Invalid index. Please try again." << std::endl;
            return;
        }
        std::cout << "Removed: " << watchlist[index - 1] << std::endl;
        watchlist.erase(watchlist.begin() + index - 1);
    }

private:
    std::vector<std::string> watchlist;
};

int main() {
    MovieWatchlist myWatchlist;
    int choice;

    do {
        std::cout << "\nMovie Watchlist Menu:" << std::endl;
        std::cout << "1. Add Movie" << std::endl;
        std::cout << "2. View Movies" << std::endl;
        std::cout << "3. Remove Movie" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore leftover newline

        switch (choice) {
            case 1: {
                std::string movie;
                std::cout << "Enter movie name: ";
                std::getline(std::cin, movie);
                myWatchlist.addMovie(movie);
                break;
            }
            case 2:
                myWatchlist.viewMovies();
                break;
            case 3: {
                int index;
                std::cout << "Enter movie index to remove: ";
                std::cin >> index;
                myWatchlist.removeMovie(index);
                break;
            }
            case 4:
                std::cout << "Exiting the application." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 4);

    return 0;
}
