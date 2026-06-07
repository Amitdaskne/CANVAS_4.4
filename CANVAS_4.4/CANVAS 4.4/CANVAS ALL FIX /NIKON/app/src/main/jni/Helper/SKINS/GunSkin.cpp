struct OutfitData {
    const char* name;
    int itemId;
};

OutfitData g_Outfits[] = {

  /*  {"Dark Raven X-Suit", 1405870},
	{"Marmoris X-Suit", 1406971},
	{"Crimson Ephialtes Set", 1406897},
    {"Luminous Muse Set", 1407225},
    {"Avalanche X-Suit", 1406152},
    {"Poseidon X-Suit", 1407140},
    {"Fiore X-Suit", 1407103},
    {"Silvanus X-Suit", 1407142},
    {"Ignis X-Suit", 1407219},
    {"Galadria X-Suit", 1407366},
    {"Anukhra X-Suit", 1407512},
    {"Golden Pharaoh X-Suit", 1405628},
	{"Foxy Flare Set", 1407106},
    {"The Lover's Grace Set", 1407276},
    {"Vampyra Countess Set", 1407391},
    {"Mercury Soldier Set", 1407285},
    {"Devious Cybercat Set", 1407286},
    {"Inferno Fiend Set", 1410668},
    {"Serpengleam Set", 1407161},
    {"Snowstar Sweetheart Set", 1407441},
    {"Sandsylph Scion Set", 1407522},
    {"Jadefang Aurora Set", 1407471},
    {"Winter Highness Set", 1407107},
    {"The Sun's Ascendance Set", 1407558},
    {"Moonlit Fantasy Set", 1406118},
    {"Chromatic Brilliance Set", 1406119},
    {"Red Commander Set", 1405593},
    {"Charged Armor Set", 1405481},
    {"Dazzling Youth Set", 1405583},
    {"Arctic Witch Set", 1405384},
    {"Red Bowtie Set", 1405426},
    {"Wedding Dress", 1405174},
    {"Legacy Set", 1405073},
    {"Smooth Hitman Set (Cat)", 1405090},
    {"The Fool Set", 1405092},
    {"Black Shark Diving Suit", 931400288},
    {"Chill Flow Set", 1407468},
    {"Adventurer Set", 1405045},
    {"Retro Anniversary Set", 1405097},
    {"Paradise Bikini (White)", 1400377},
    {"Bunny Girl Set", 1405487},
    {"Deadly Feline Set", 1405026},
    {"Chic Boxhead Set", 1407211},
    {"Bonds of Ruby Set", 1406060},
    {"Dream Idol Set", 1405802},
    {"Godzilla's Carapace", 12205101},
    */
};

struct PlayerOutfit {
    std::atomic<int> currentOutfit;
};

PlayerOutfit g_PlayerOutfit;

bool ReplaceItemId(int& itemId, const std::unordered_map<std::string, std::string>& mapTable) {
    auto it = mapTable.find(std::to_string(itemId));
    if (it != mapTable.end()) {
        itemId = std::stoi(it->second);
        return true;
    }
    return false;
}
//==============================================================================/
//==============================================================================/
std::unordered_map<int, int> Parachute = {
    {703001, 1401621}
};
//==============================================================================/
std::unordered_map<int, int> Bagpack = {
    {501001, 1501001698},//1501001629
    {501002, 1501002698},
    {501003, 1501003698},
    {501004, 1501001698},
	{501005, 1501002698},
    {501006, 1501003698},
    {501101, 1501001698},
    {501102, 1501002698},
	{501103, 1501003698},
    {501104, 1501001698},
    {501105, 1501002698},
    {501106, 1501003698},
    {1501001013,1501001220},
    {1501002013,1501002220},
    {1501003013,1501003220},
    {1501002015,1501002625},
    {1501002025,1501002625},
    {1501003025,1501003625}
};
//==============================================================================/
std::unordered_map<int, int> Helmet = {
    {502001, 0}, //Lvl-1
    {502004, 0},
    {502114, 0},
    {502002, 0}, //Lvl-2
    {502005, 0},
    {502115, 0},
    {502003, 0}, //Lvl-3
    {502116, 0},
    {502101, 0}, //Lvl-1
    {502102, 0}, //Lvl-2
    {502103, 0} //Lvl-3
};
//==============================================================================/
std::unordered_map<int, int> FaceSkin = {
	{401985, 1400563}, // 
	{401990, 1400563}, // 
    {401991, 1400563}, // 
    {401992, 1400563}, // 
    {401993, 1400563}, // Face A
    {401994, 1400563}, // Face G
    {401995, 1400563}, // Face F
    {401996, 1400563}, // Face E
    {401997, 1400563}, // Face D
    {401998, 1400563}, // Face C
    {401999, 1400563}  // Face B
};
//==============================================================================/
std::unordered_map<int, int> HairSkin = {
    {40601001, 40605011}, // Hair A
    {40604002, 40605011}, // Hair B
    {40604003, 40605011}, // Hair C
    {40604004, 40605011}, // Hair D
    {40604005, 40605011}, // Hair E
    {40604006, 40605011}, // Hair F
    {40604007, 40605011}, // Hair G
    {40604008, 40605011}, // Hair H
    {40604009, 40605011}  // Hair I
};


std::unordered_map<int, int> VehicleSkinMap = {
    {1961001, 1961021},  // Coupe RB
    {1907002, 1907054},  // Buggy
    {1915001, 1915006},  // Mirado Open
    {1915002, 1915006},  // Mirado Open
    {1915003, 1915006},  // Mirado Open
    {1915004, 1915006},  // Mirado Open
    {1903001, 1903201},  // Dacia
    {1906002, 1901070},  // PickUp
    {1908001, 1908070},  // UAZ
    {1904001, 1904013},  // MiniBus
    {1902002, 1902018},  // Motorcycle Triple
    {1901002, 1901077},  // Motorcycle
    {1917001, 1917006},  // Scooter
    {1987001, 1987002}   // Ghoda
};


std::unordered_map<int, int> ModSkinsID = {
    {101004, 1101004046}, // M416 GLACIER
    {101001, 1101001213}, // Starsea Admiral - AKM
    {101002, 1101002081}, // Skeletal Core - M16A4 
    {101003, 1101003195}, // Serene Lumina - SCAR-L
    {101005, 1101005052}, // River Styx - Groza
    {101006, 1101006075}, // Abyssal Howl - AUG
    {101007, 1101007062}, // Fatal Foil - QBZ
    {101008, 1101008051}, // Concerto of Love - M762
	{101102, 1101102007}, // Beam Blast - ACE32
    {101100, 1101100012}, // Origin Lumen - FAMAS
	{103003, 1103003087}, // Serpengleam - AWM
    {103002, 1103002087}, // Cadence Maestro - M24
	{103001, 1103001179}, // Violet Volt - Kar98K
    {103012, 1103012019}, // Scorching Blessing - AMR
	{103007, 1103007028}, // Drakreign - Mk14
    {103004, 1103004037}, // Lady Carmine - SKS
	{103006, 1103006030}, // Icicle - Mini14
    {105010, 1105010019}, // Sky Huntress - MG3
	{102001, 1102001120}, // Glacier Hammer - UZI
    {102002, 1102002136}, // Cryofrost Shard - UMP45
	{102003, 1102003080}, // Mecha Drake - Vector
    {103009, 1103009022}, // Falling Blossom - SLR
    {105001, 1105001062}, // Graffiti Street - M249
    {103100, 1103100007}, // Precise Predator - Mk12
	{105002, 1105002076}, // Data Kitten - DP-28
    {102004, 1102004018}, // Candy Cane - Thompson
    {102005, 1102005052}, // DP Quantum Quake  - Bizon
    {103005, 1103005024}, // Crow - VSS
    {102105, 1102105012}, // Devious Cybercat - P90
    {104003, 1104003026}, // S12K GACKT
    {104002, 1104002022}, // Twilight Hunt - S1897
    {104004, 1104004035}, // Cosmic Beast - DBS
    {101012, 1101012009}, // Vivid Glare - Honey Badger
    {108004, 1108004365}, // PAN
    {108001, 1108001057}, // Machete
    {108005, 1108005050}  // Dagger
};
//--------------SKINS WITH THEIR ATTACHMENTS-------------\\
// M416 Skin Map
std::unordered_map<int, int> M416SkinsID = {
    {101004, 1101004046}, // M416 GLACIER
    {203008, 1010040462}, // Sight
    {291004, 1010040461}, // Magazine
    {205005, 1010040463}, // Stock
    {203001, 1010040470}, // Red Dot
    {203002, 1010040469}, // Holo
    {203003, 1010040468}, // 2X
    {203014, 1010040467}, // 3X
    {203004, 1010040466}, // 4X
    {203015, 1010040481}, // 6X
    {202002, 1010040479}, // Vertical Grip
    {202001, 1010040477}, // Angled Grip
    {202004, 1010040482}, // Light Grip
    {202005, 1010040483}, // Half Grip
    {202006, 1010040478}, // Thumb Grip
    {205002, 1010040480}, // Tactical Stock
    {201010, 1010040474}, // Flash Hider
    {201011, 1010040476}, // Suppressor AR
    {201009, 1010040475}, // Compensator AR
    {204012, 1010040472}, // Quick Draw Mag
    {204011, 1010040471}, // Extended Mag
    {204013, 1010040473}  // Extended QuickDraw Mag
};

// AKM Skin Map
std::unordered_map<int, int> AKMSkinsID = {
    {101001, 1101001213}, // Starsea Admiral - AKM
	{203001, 1010012066}, // Red Dot
    {203002, 1010012065}, // Holo
    {203003, 1010012064}, // 2X
    {203014, 1010012063}, // 3X
    {203004, 1010012062}, // 4X
    {203015, 1010012075}, // 6X
    {204011, 1010012070}, // Extended Mag
    {204012, 1010012072}, // Quick Draw Mag
    {204013, 1010012073}, // Extended QuickDraw Mag
	{201010, 1010012067}, // Flash Hider
    {201011, 1010012069}, // Suppressor AR
    {201009, 1010012068}  // Compensator AR
};

// M16A4 Skin Map
std::unordered_map<int, int> M16A4SkinsID = {
    {101002, 1101002081}, // Skeletal Core - M16A4 
    {203001, 1010020759}, // Red Dot
    {203002, 1010020758}, // Holo
    {203003, 1010020757}, // 2X
    {203014, 1010020756}, // 3X
    {203004, 1010020755}, // 4X
    {204012, 1010020766}, // Quick Draw Mag
    {204011, 1010020760}, // Extended Mag
    {204013, 1010020767}, // Extended QuickDraw Mag
	{201010, 1010020768}, // Flash Hider
    {201011, 1010020770}, // Suppressor AR
    {201009, 1010020769}, // Compensator AR
	{205002, 1010020775}  // Tactical Stock
};

// SCAR-L Skin Map
std::unordered_map<int, int> SCARLSkinsID = {
    {101003, 1101003195}, // Serene Lumina - SCAR-L
    {203001, 1010031906}, // Red Dot
    {203002, 1010031905}, // Holo
    {203003, 1010031904}, // 2X
    {203014, 1010031903}, // 3X
    {203004, 1010031902}, // 4X
    {203015, 1010031901}, // 6X
    {204011, 1010031907}, // Extended Mag 
    {204012, 1010031908}, // Quickdraw Mag 
    {204013, 1010031909}, // Extended Quickdraw Mag 
    {201009, 1010031911}, // Compensator
	{201010, 1010031912}, // Flash Hider
    {201011, 1010031913}, // Suppressor
    {202001, 1010031914}, // Angled Grip
    {202006, 1010031915}, // Thumb Grip
    {202002, 1010031916}, // Vertical Grip
    {202004, 1010031918}, // Light Grip
    {202005, 1010031919}  // Half Grip
};

// GROZA Skin Map
std::unordered_map<int, int> GROZASkinsID = {
    {101005, 1101005052}, // River Styx - Groza
    {203002, 1010050465}, // Holo
    {203003, 1010050464}, // 2X
    {203014, 1010050463}, // 3X
    {203004, 1010050462}, // 4X
    {203015, 1010050473}, // 6X
    {204011, 1010050468}, // Extended Mag 
    {204012, 1010050469}, // Quickdraw Mag 
    {204013, 1010050470}, // Extended Quickdraw Mag 
    {201011, 1010050467}  // Suppressor
};

// AUG Skin Map
std::unordered_map<int, int> AUGSkinsID = {
    {101006, 1101006075}, // Abyssal Howl - AUG
    {203001, 1010060696}, // Red Dot
    {203002, 1010060695}, // Holo
    {203003, 1010060694}, // 2X
    {203014, 1010060693}, // 3X
    {203004, 1010060692}, // 4X
    {203015, 1010060691}, // 6X
    {204011, 1010060697}, // Extended Mag 
    {204012, 1010060698}, // Quickdraw Mag 
    {204013, 1010060699}, // Extended Quickdraw Mag 
    {201009, 1010060701}, // Compensator
	{201010, 1010060702}, // Flash Hider
    {201011, 1010060703}, // Suppressor
    {202001, 1010060704}, // Angled Grip
    {202006, 1010060705}, // Thumb Grip
    {202002, 1010060706}, // Vertical Grip
    {202004, 1010060708}, // Light Grip
    {202005, 1010060709}  // Half Grip
};

// QBZ Skin Map
std::unordered_map<int, int> QBZSkinsID = {
    {101007, 1101007062}, // Fatal Foil - QBZ
    {203001, 1010070574}, // Red Dot
    {203002, 1010070573}, // Holo
    {203003, 1010070572}, // 2X
    {203014, 1010070571}, // 3X
    {203004, 1010070569}, // 4X
    {203015, 1010070568}, // 6X
    {204011, 1010070575}, // Extended Mag 
    {204012, 1010070576}, // Quickdraw Mag 
    {204013, 1010070577}, // Extended Quickdraw Mag 
    {201009, 1010070578}, // Compensator
	{201010, 1010070579}, // Flash Hider
    {201011, 1010070581}, // Suppressor
    {202001, 1010070582}, // Angled Grip
    {202006, 1010070583}, // Thumb Grip
    {202002, 1010070584}, // Vertical Grip
    {202004, 1010070585}, // Light Grip
    {202005, 1010070586}  // Half Grip
};

// M762 Skin Map
std::unordered_map<int, int> M762SkinsID = {
    {101008, 1101008051} // Concerto of Love - M762
};

// ACE32 Skin Map
std::unordered_map<int, int> ACE32SkinsID = {
    {101102, 1101102007}, // Beam Blast - ACE32
	{203001, 1011020019}, // Red Dot
    {203002, 1011020018}, // Holo
    {203003, 1011020017}, // 2X
    {203014, 1011020016}, // 3X
    {203004, 1011020015}, // 4X
    {203015, 1011020014}, // 6X
    {204011, 1011020024}, // Extended Mag 
    {204012, 1011020025}, // Quickdraw Mag 
    {204013, 1011020026}, // Extended Quickdraw Mag 
    {201009, 1011020028}, // Compensator
	{201010, 1011020027}, // Flash Hider
    {201011, 1011020029}, // Suppressor
    {202001, 1011020034}, // Angled Grip
    {202006, 1011020035}, // Thumb Grip
    {202002, 1011020036}, // Vertical Grip
    {202004, 1011020038}, // Light Grip
    {202005, 1011020039}, // Half Grip
	{205002, 1011020037}  // Tactical Stock
};

// FAMAS Skin Map
std::unordered_map<int, int> FAMASSkinsID = {
    {101100, 1101100012}, // Origin Lumen - FAMAS
	{203001, 1011020019}, // Red Dot
    {203002, 1011020018}, // Holo
    {203003, 1011020017}, // 2X
    {203014, 1011020016}, // 3X
    {203004, 1011020015}, // 4X
    {203015, 1011000053}, // 6X
	{201009, 1011020028}, // Compensator
	{201010, 1011020027}, // Flash Hider
    {201011, 1011020029}  // Suppressor
};

// AWM Skin Map
std::unordered_map<int, int> AWMSkinsID = {
    {103003, 1103003087}, // Serpengleam - AWM
	{203001, 1030030818}, // Red Dot
    {203002, 1030030817}, // Holo
    {203003, 1030030816}, // 2X
    {203014, 1030030815}, // 3X
    {203004, 1030030814}, // 4X
    {203015, 1030030813}, // 6X
    {203005, 1030030812}, // 8X
	{204007, 1030030822}, // Extended Mag 
	{204008, 1030030823}, // Quickdraw Mag
	{204009, 1030030824}, // Extended Quickdraw Mag 
    {201005, 1030030825}, // Flash Hider 
	{201003, 1030030826}, // Compensator 
    {201007, 1030030827}, // Suppressor 
    {205003, 1030030828}  // Cheek Pad 
};

// M24 Skin Map
std::unordered_map<int, int> M24SkinsID = {
    {103002, 1103002087}, // Cadence Maestro - M24
	{203001, 1030020818}, // Red Dot
    {203002, 1030020817}, // Holo
    {203003, 1030020816}, // 2X
    {203014, 1030020815}, // 3X
    {203004, 1030020814}, // 4X
    {203015, 1030020813}, // 6X
    {203005, 1030020812}, // 8X
    {201005, 1030020824}, // Flash Hider 
	{201003, 1030020825}, // Compensator 
    {201007, 1030020826}, // Suppressor 
    {205003, 1030020827}  // Cheek Pad 
};

// KAR98K Skin Map
std::unordered_map<int, int> KAR98KSkinsID = {
    {103001, 1103001179}, // Violet Volt - Kar98K
	{203001, 1030011737}, // Red Dot
    {203002, 1030011736}, // Holo
    {203003, 1030011735}, // 2X
    {203014, 1030011734}, // 3X
    {203004, 1030011733}, // 4X
    {203015, 1030011732}, // 6X
    {203005, 1030011731}, // 8X
    {201005, 1030011738}, // Flash Hider 
	{201003, 1030011739}, // Compensator 
    {201007, 1030011741}, // Suppressor 
    {205003, 1030011742}  // Cheek Pad 
};

// AMR Skin Map
std::unordered_map<int, int> AMRSkinsID = {
    {103012, 1103012019}, // Scorching Blessing - AMR
	{203001, 1030120138}, // Red Dot
    {203002, 1030120137}, // Holo
    {203003, 1030120136}, // 2X
    {203014, 1030120135}, // 3X
    {203004, 1030120134}, // 4X
    {203015, 1030120133}, // 6X
    {203005, 1030120132}, // 8X
};

// MK14 Skin Map
std::unordered_map<int, int> MK14SkinsID = {
    {103007, 1103007028}, // Drakreign - Mk14
	{203001, 1030070218}, // Red Dot
    {203002, 1030070217}, // Holo
    {203003, 1030070216}, // 2X
    {203014, 1030070215}, // 3X
    {203004, 1030070214}, // 4X
    {203015, 1030070213}, // 6X
    {203005, 1030070212}, // 8X
	{204007, 1030070225}, // Extended Mag (Snipers) 
	{204008, 1030070226}, // Quickdraw Mag (Snipers) 
	{204009, 1030070227}, // Extended Quickdraw Mag (Snipers) 
    {201005, 1030070233}, // Flash Hider (Snipers) 
	{201003, 1030070234}, // Compensator (Snipers) 
    {201007, 1030070235}, // Suppressor (Snipers) 
	{204011, 1030070222}, // Extended Mag (AR) 
    {204012, 1030070223}, // Quickdraw Mag (AR) 
    {204013, 1030070224}, // Extended Quickdraw Mag (AR) 
	{201010, 1030070228}, // Flash Hider (AR) 
    {201009, 1030070229}, // Compensator (AR) 
    {201011, 1030070232}, // Suppressor (AR) 
    {205003, 1030070236}  // Cheek Pad 
};


// SKS Skin Map
std::unordered_map<int, int> SKSSkinsID = {
    {103004, 1103004037}, // Lady Carmine - SKS
	{203004, 1030040314}, // 4X
    {203015, 1030040313}, // 6X
    {203005, 1030040312}, // 8X
	{204007, 1030040319}, // Extended Mag (Snipers) 
	{204008, 1030040322}, // Quickdraw Mag (Snipers) 
	{204009, 1030040318}, // Extended Quickdraw Mag (Snipers) 
	{204013, 1030040323}, // Extended Quickdraw Mag (AR) 
    {204012, 1030040325}, // Quickdraw Mag (AR) 
    {204011, 1030040324}, // Extended Mag (AR) 
	{202002, 1030040327}, // Vertical Grip
    {202001, 1030040326}, // Angled Grip
    {202006, 1030040328}, // Thumb Grip
	{201005, 1030040315}, // Flash Hider 
	{201003, 1030040316}, // Compensator 
    {201007, 1030040317}, // Suppressor 
    {205003, 1030040329}  // Cheek Pad 
};

// MINI14 Skin Map
std::unordered_map<int, int> MINI14SkinsID = {
    {103006, 1103006030}, // Icicle - Mini14
    {203004, 1030060244}, // 4X
    {203015, 1030060243}, // 6X
    {203005, 1030060242}, // 8X
	{201005, 1030060245}, // Flash Hider 
	{201003, 1030060246}, // Compensator 
    {201007, 1030060247}, // Suppressor 
	{204007, 1030060249}, // Extended Mag (Snipers) 
	{204009, 1030060248}, // Extended Quickdraw Mag (Snipers) 
	{204013, 1030060252}, // Extended Quickdraw Mag (AR) 
    {204011, 1030060253}  // Extended Mag (AR) 
};

// MG3 Skin Map
std::unordered_map<int, int> MG3SkinsID = {
    {105010, 1105010019}, // Sky Huntress - MG3
	{203001, 1050100144}, // Red Dot
    {203002, 1050100143}, // Holo
    {203003, 1050100142}, // 2X
    {203014, 1050100141}, // 3X
    {203004, 1050100139}, // 4X
    {203015, 1050100138}  // 6X
};

// UZI Skin Map
std::unordered_map<int, int> UZISkinsID = {
    {102001, 1102001120}, // Glacier Hammer - UZI
    {203001, 1020011133}, // Red Dot Sight 
	{203002, 1020011132}, // Holographic Sight 
    {204004, 1020011134}, // Extended Mag 
    {204005, 1020011135}, // Quickdraw Mag 
    {204006, 1020011136}, // Extended Quickdraw Mag 
    {201004, 1020011137}, // Flash Hider 
    {201002, 1020011138}, // Compensator 
    {201006, 1020011139}, // Suppressor 
    {205001, 1020011142}  // Stock UZI
};

// UMP45 Skin Map
std::unordered_map<int, int> UMP45SkinsID = {
    {102002, 1102002136}, // Cryofrost Shard - UMP45
	{203001, 1020021306}, // Red Dot
    {203002, 1020021306}, // Holo
    {203003, 1020021305}, // 2X
    {203014, 1020021304}, // 3X
    {203004, 1020021303}, // 4X
    {203015, 1020021302}, // 6X
    {204004, 1020021308}, // Extended Mag 
    {204005, 1020021309}, // Quickdraw Mag 
    {204006, 1020021312}, // Extended Quickdraw Mag 
	{201004, 1020021314}, // Flash Hider 
    {201002, 1020021313}, // Compensator 
    {201006, 1020021315}, // Suppressor 
    {202002, 1020021318}, // Vertical Grip
    {202001, 1020021316}, // Angled Grip
    {202004, 1020021323}, // Light Grip
    {202005, 1020021324}, // Half Grip
    {202006, 1020021317}  // Thumb Grip
};

// VECTOR Skin Map
std::unordered_map<int, int> VECTORSKinsID = {
    {102003, 1102003080}, // Mecha Drake - Vector
	{203001, 1020030748}, // Red Dot
    {203002, 1020030747}, // Holo
    {203003, 1020030746}, // 2X
    {203014, 1020030745}, // 3X
    {203004, 1020030744}, // 4X
    {203015, 1020030764}, // 6X
	{204004, 1020030749}, // Extended Mag 
    {204005, 1020030750}, // Quickdraw Mag 
    {204006, 1020030754}, // Extended Quickdraw Mag 
	{201004, 1020030755}, // Flash Hider 
    {201002, 1020030756}, // Compensator 
    {201006, 1020030758}, // Suppressor 
    {202005, 1020030757}, // Half Grip
    {202004, 1020030759}, // Light Grip
    {202002, 1020030760}, // Vertical Grip
	{205002, 1020030765}  // Tactic Stock
};

// SLR Skin Map
std::unordered_map<int, int> SLRSkinsID = {
    {103009, 1103009022} // Falling Blossom - SLR
};

// M249 Skin Map
std::unordered_map<int, int> M249SkinsID = {
    {105001, 1105001062} // Graffiti Street - M249
};

// MK12 Skin Map
std::unordered_map<int, int> MK12SkinsID = {
    {103100, 1103100007} // Precise Predator - Mk12
};

// DP28 Skin Map
std::unordered_map<int, int> DP28SkinsID = {
    {105002, 1105002076} // Data Kitten - DP-28
};

// THOMPSON Skin Map
std::unordered_map<int, int> THOMPSONSkinsID = {
    {102004, 1102004018} // Candy Cane - Thompson
};

// BIZON Skin Map
std::unordered_map<int, int> BIZONSkinsID = {
    {102005, 1102005052} // DP Quantum Quake  - Bizon
};

// VSS Skin Map
std::unordered_map<int, int> VSSSkinsID = {
    {103005, 1103005024} // Crow - VSS
};

// P90 Skin Map
std::unordered_map<int, int> P90SkinsID = {
    {102105, 1102105012} // Devious Cybercat - P90
};

// S12K Skin Map
std::unordered_map<int, int> S12KSkinsID = {
    {104003, 1104003026} // S12K GACKT
};

// S1897 Skin Map
std::unordered_map<int, int> S1897SkinsID = {
    {104002, 1104002022} // Twilight Hunt - S1897
};

// DBS Skin Map
std::unordered_map<int, int> DBSSkinsID = {
    {104004, 1104004035} // Cosmic Beast - DBS
};

// Honey Badger Skin Map
std::unordered_map<int, int> HoneyBadgerSkinsID = {
    {101012, 1101012009} // Vivid Glare - Honey Badger
};

// PAN Skin Map
std::unordered_map<int, int> PANSkinsID = {
    {108004, 1108004365}  //PAN
};

// Machete Skin Map
std::unordered_map<int, int> MacheteSkinsID = {
    {108001, 1108001057}  //Machete
};

// Dagger Skin Map
std::unordered_map<int, int> DaggerSkinsID = {
    {108005, 1108005050}  //Dagger
};
