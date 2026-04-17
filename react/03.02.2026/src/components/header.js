function Header() {
    const styles = {
        header: {
            background: "#221f1f",
            color: "#fff",
            fontFamily: "Inter, Arial, sans-serif",
            height: "64px",
            display: "flex",
            justifyContent: "center",
        },

        container: {
            width: "100%",
            maxWidth: "1600px",
            padding: "0 24px",
            display: "flex",
            alignItems: "center",
            gap: "16px",
            justifyContent: "center",
        },

        burger: {
            width: "28px",
            height: "28px",
            cursor: "pointer",
            opacity: 0.9,
        },

        logoWrap: {
            display: "flex",
            alignItems: "center",
            marginRight: "8px",
            cursor: "pointer",
        },

        logoImg: {
            height: "32px",
        },

        catalogBtn: {
            display: "flex",
            alignItems: "center",
            justifyContent: "center",
            gap: "8px",
            height: "40px",
            padding: "0 14px",
            background: "none",
            border: "none",
            borderRadius: "8px",
            border: "1px solid #fff",
            color: "#fff",
            fontSize: "16px",
            fontWeight: "500",
            cursor: "pointer",
            whiteSpace: "nowrap",
        },

        searchWrap: {
            display: "flex",
            alignItems: "center",
            flexGrow: 1,
            maxWidth: "720px",
            height: "40px",
            background: "#fff",
            borderRadius: "8px",
            overflow: "hidden",
        },

        searchInput: {
            flexGrow: 1,
            height: "100%",
            border: "none",
            outline: "none",
            padding: "0 12px",
            fontSize: "14px",
            color: "#221f1f",
        },

        searchBtn: {
            height: "100%",
            padding: "0 20px",
            background: "#00a046",
            border: "none",
            color: "#fff",
            fontSize: "14px",
            fontWeight: "600",
            cursor: "pointer",
            borderRadius: "8px",
        },

        icons: {
            display: "flex",
            alignItems: "center",
            gap: "18px",
            marginLeft: "12px",
        },

        iconWrap: {
            width: "40px",
            height: "40px",
            display: "flex",
            alignItems: "center",
            justifyContent: "center",
            cursor: "pointer",
        },

        icon: {
            width: "32px",
            height: "32px",
        },
    };

    return (
        <header style={styles.header}>
            <div style={styles.container}>
                <img src="/images/burger.svg" style={styles.burger} />

                <div style={styles.logoWrap}>
                    <img src="/images/logo.svg" style={styles.logoImg} />
                </div>

                <button style={styles.catalogBtn}>
                    <img src="/images/catalog.svg" width="16" />
                    Каталог
                </button>

                <div style={styles.searchWrap}>
                    <input
                        style={styles.searchInput}
                        placeholder="Я шукаю..."
                    />
                    <button style={styles.searchBtn}>Знайти</button>
                </div>

                <div style={styles.icons}>
                    <div style={styles.iconWrap}>
                        <img src="/images/user.svg" style={styles.icon} />
                    </div>
                    <div style={styles.iconWrap}>
                        <img src="/images/scale.svg" style={styles.icon} />
                    </div>
                    <div style={styles.iconWrap}>
                        <img src="/images/cart.svg" style={styles.icon} />
                    </div>
                </div>
            </div>
        </header>
    );
}

export default Header;